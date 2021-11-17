//
//  FileNormalizationHelper.swift
//  AirMessage
//
//  Created by Cole Feuer on 2021-11-15.
//

import Foundation

struct NormalizedFile {
	let url: URL
	let type: String
	let name: String
}

/**
 Converts a file from Apple-specific formats to formats that are readable by non-Apple devices.
 The resulting file is stored in a temporary location, and should be cleaned up after it is finished being used.
 This function does not modify or remove the input file.
 - Parameters:
   - inputFile: The file to process
   - extension: The extension type of the file
 - Returns: A tuple with the updated file path and string, or NIL if the file was not converted
 */
func normalizeFile(url inputFile: URL, ext: String) -> NormalizedFile? {
	/*
	 These conversions are only available on macOS 10.13+,
	 but older versions have these files converted before they
	 even reach the device anyways
	 */
	guard #available(macOS 10.13, *) else { return nil }
	
	if ext == "heic" {
		LogManager.shared.log("Converting file %{public} from HEIC", type: .info, inputFile.path)
		
		//Get a temporary file
		let tempFile = URL(fileURLWithPath: NSTemporaryDirectory(), isDirectory: true).appendingPathComponent(UUID().uuidString + ".jpeg")
		
		//Convert the file with sips
		let process = Process()
		process.executableURL = URL(fileURLWithPath: "/usr/bin/sips")
		process.arguments = ["--setProperty", "format", "jpeg", inputFile.path, "--out", tempFile.path]
		let processResult = runProcessLogError(process)
		
		//Check the process result
		guard processResult else {
			LogManager.shared.log("Failed to convert file %{public} from HEIC to JPEG: %{public}", type: .info, inputFile.path)
			try? FileManager.default.removeItem(at: tempFile) //Clean up immediately
			return nil
		}
		
		//Build the new file name
		let newFileName = inputFile.deletingPathExtension().lastPathComponent + ".jpeg"
		
		return NormalizedFile(url: tempFile, type: "image/jpeg", name: newFileName)
	} else if ext == "caf" {
		LogManager.shared.log("Converting file %{public} from CAF", type: .info, inputFile.path)
		
		//Get a temporary file
		let tempFile = URL(fileURLWithPath: NSTemporaryDirectory(), isDirectory: true).appendingPathComponent(UUID().uuidString + ".mp4")
		
		//Convert the file with sips
		let process = Process()
		process.executableURL = URL(fileURLWithPath: "/usr/bin/afconvert")
		process.arguments = ["-f", "mp4f", "-d", "aac", inputFile.path, "-o", tempFile.path]
		let processResult = runProcessLogError(process)
		
		//Check the process result
		guard processResult else {
			LogManager.shared.log("Failed to convert file %{public} from CAF to MP4: %{public}", type: .info, inputFile.path)
			try? FileManager.default.removeItem(at: tempFile) //Clean up immediately
			return nil
		}
		
		//Build the new file name
		let newFileName = inputFile.deletingPathExtension().lastPathComponent + ".mp4"
		
		return NormalizedFile(url: tempFile, type: "audio/mp4", name: newFileName)
	} else {
		return nil
	}
}

/**
 Starts a process, waits for it to finish, and logs any errors the process encountered while running
 - Parameters:
   - process: The process to start and monitor
 - Returns: Whether the process ran successfully
 */
@available(macOS 10.13, *)
private func runProcessLogError(_ process: Process) -> Bool {
	//Capture the process' error pipe
	let errorPipe = Pipe()
	process.standardError = errorPipe
	
	//Start the process
	do {
		try process.run()
	} catch {
		LogManager.shared.log("An error occurred while running process: %{public}", type: .info, error.localizedDescription)
		return false
	}
	
	//Wait for the process to exit
	process.waitUntilExit()
	
	//Check the output code
	guard process.terminationStatus == 0 else {
		let errorFileHandle = errorPipe.fileHandleForReading
		
		let errorMessage: String?
		if let data = try? errorFileHandle.readToEndCompat(), !data.isEmpty {
			errorMessage = String(data: data, encoding: .utf8)
		} else {
			errorMessage = nil
		}
		
		LogManager.shared.log("An error occurred while running process: %{public}", type: .info, errorMessage ?? "Unknown error")
		return false
	}
	
	return true
}