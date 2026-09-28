import os
import time
import psutil
import platform

def isProcessRunning(process_name):
    for proc in psutil.process_iter(attrs=['pid', 'name']):
        if process_name.lower() in proc.info['name'].lower():
            return True
    return False

def getUserLogPath():
    userLogPath = input("copy and paste the absolute file path to your obs studio log directory: ")
    if platform.system() == "Windows":
        userLogPath = userLogPath.replace("\\", "\\\\")
    return userLogPath

def getNewestFile(directory):
    fileList = os.listdir(directory)
    newestFileMTime = 0
    newestFilePath = ""
    for file in fileList:
        currentFile = os.path.getmtime(os.path.join(directory, file))
        if currentFile > newestFileMTime: 
            newestFileMTime = currentFile
            newestFilePath = os.path.join(directory, file)
    return newestFilePath


def startFileChangeFound(logFile):
    with open(logFile, 'r') as file:
        file.seek(0, 2)
        while True:
            line = file.readline()
            if not line:
                time.sleep(0.1)
                continue
            if "start file changes" in line:
                return True
