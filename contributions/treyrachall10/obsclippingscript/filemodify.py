import os
import platform

specialChars = [" ", "!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "-", "_", "=", "+", "[", "]", "{", "}", "\\", "|", ";", ":", "'", "\"", ",", ".", "<", ">", "/", "?"]

def getUserVideoPath():
    videoFilePath = input("copy and paste the absolute file path from OBS Studio recording output settings: ")
    if platform.system() ==  "Windows":
        videoFilePath = videoFilePath.replace("\\", "\\\\")
    return videoFilePath
    
def getEntryField(recordingPath):
    category = input("Enter Name of category Ex: exciting, nonexciting: ").lower()
    move = input("Enter Name of move NO SPACES Ex: submission, sweep, takedown: ").lower()
    while True:
        if category != "exciting" and category != "nonexciting":
            category = input("TRY AGAIN category did not match parameters (exciting, nonexciting): ").lower()
            continue
        if any(char in specialChars for char in move):
            move = input("TRY AGAIN move input had spaces: ").lower()
            continue
        break
    finalFilePath = getNewFileName(recordingPath, category, move)
    return finalFilePath

def getNewFileName(recordingPath, category, move):
    newFilePath = checkFileName(recordingPath, category, move)
    return newFilePath

def getNewFilePath(recordingPath, newName):
    return os.path.join(recordingPath, f"{newName}.mp4")

def assignFileName(oldPath, newPath):
    os.rename(oldPath, newPath)

def checkFileName(recordingPath, category, moveName):
    counter = 1
    while True:
        newName = f"{category}_{moveName}_{counter}"
        newFilePath = getNewFilePath(recordingPath, newName)
        if not os.path.exists(newFilePath):
            return newFilePath
        counter += 1
