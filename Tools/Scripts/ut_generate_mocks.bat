@echo off
setlocal EnableDelayedExpansion

REM Check if the project root and module path are provided
if "%~1"=="" (
    echo Usage: %~nx0 ^<project_root^> ^<module_path^>
    echo Example: %~nx0 C:\path\to\project Sw_Components\01_App\MotorCtrl\motor_ctrl_UT
    exit /b 1
)

if "%~2"=="" (
    echo Please provide the path to the UT module.
    exit /b 1
)

REM Set the project root and module path from arguments
set "PROJECT_ROOT=%~1"
set "MODULE_PATH=%~2"

REM Path to CMock script and mock config (relative to the module)
set "CMOCK_PATH=%PROJECT_ROOT%\Tools\Unit_Testing\Cmock\lib\cmock.rb"
set "YML_CONFIG=%PROJECT_ROOT%\%MODULE_PATH%\gcc.yml"

REM Path to the mock headers file located inside the specified UT module
set "HEADERS_FILE=%PROJECT_ROOT%\%MODULE_PATH%\mock_headers.txt"

REM Check if the mock headers file exists
if not exist "%HEADERS_FILE%" (
    echo Headers file not found at %HEADERS_FILE%
    exit /b 1
)

REM Read the headers from the mock headers file and build the list
set "HEADERS="
for /f "usebackq tokens=*" %%h in ("%HEADERS_FILE%") do (
    set "HEADERS=!HEADERS! %PROJECT_ROOT%\%%h"
)

REM Run the ruby command with the collected headers
echo Generating mocks for module: %MODULE_PATH% using headers:
echo !HEADERS!
ruby "%CMOCK_PATH%" -o"%YML_CONFIG%" !HEADERS!
if errorlevel 1 (
    echo CMock generation failed for %MODULE_PATH%
    exit /b 1
)

echo CMock generation succeeded for module: %MODULE_PATH%
exit /b 0
