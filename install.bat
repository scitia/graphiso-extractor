@echo off

REM
set SOURCE_DIR=%~dp0src
set BUILD_DIR=%~dp0build

REM
if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

REM
cd /d "%BUILD_DIR%"

REM
cmake .. -G "MinGW Makefiles"

REM
cmake --build .

REM
REM
"%BUILD_DIR%\graphiso-extractor.exe"