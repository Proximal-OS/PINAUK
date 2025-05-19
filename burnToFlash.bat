@echo off
setlocal enabledelayedexpansion

:: Check if we already stored the script dir
if not exist "C:\PBFT\temp.txt" (
    REM Store script directory before elevating
    set "currentDir=%~dp0"
    set "currentDir=%currentDir:~0,-1%"
    mkdir C:\PBFT >nul 2>&1
    REM echo %currentDir% > C:\PBFT\temp.txt
	(
    echo %~dp0
) > C:\PBFT\temp.txt


    REM Relaunch with admin rights
    echo Requesting admin privileges...
    powershell -Command "Start-Process '%~f0' -Verb runAs"
    exit /b
)

:: We're now elevated. Load the previously stored script directory
set /p ScriptDir=<C:\PBFT\temp.txt

:: Show available disks
(echo list disk
echo exit
) | diskpart

echo Select your FLASH DRIVE's disk number.
echo ALL FILES ON THAT DRIVE WILL BE DELETED.

:DiskInput
set /p PN=Enter the disk number: 
echo %PN% | findstr /r "^[0-9][0-9]*$"

:LetterInput
set /p PL=Enter a free partition letter (without ":"): 
echo %PL% | findstr /r "^[a-zA-Z]$" 

:: Diskpart: wipe, format, assign
(
    echo select disk %PN%
    echo clean
    echo create partition primary
    echo select partition 1
    echo format fs=fat32 quick
    echo assign letter=%PL%:
    echo exit
) | diskpart

:: Copy files
robocopy "%ScriptDir%\image" "%PL%:" /E /COPYALL /R:0 /W:0

:: Clean up
echo Cleaning up...
del C:\PBFT\temp.txt >nul
rmdir C:\PBFT >nul

pause
exit
