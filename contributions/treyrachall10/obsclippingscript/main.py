import time
from logfiles import *
from filemodify import *

userVideoPath = getUserVideoPath()
logPath = getUserLogPath()

while True:
    if isProcessRunning("obs") or isProcessRunning("obs-studio.exe"):
        if startFileChangeFound(getNewestFile(logPath)):
            oldVideoFilePath = getNewestFile(userVideoPath)
            newFilePath = getEntryField(userVideoPath)
            assignFileName(oldVideoFilePath, newFilePath)
    time.sleep(1)
