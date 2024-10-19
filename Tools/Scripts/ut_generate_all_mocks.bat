@echo off
setlocal EnableDelayedExpansion

REM Check if the project root and module list file are provided
if "%~1"=="" (
    echo Usage: %~nx0 ^<project_root^> ^<module_list_file^>
    echo Example: %~nx0 C:\path\to\project C:\path\to\modules_list.txt
    exit /b 1
)

if "%~2"=="" (
    echo Please provide the path to the module list file.
    exit /b 1
)

REM Set the project root and module list file from arguments
set "PROJECT_ROOT=%~1"
set "MODULES_LIST_FILE=%~2"

REM Check if the module list file exists
if not exist "%MODULES_LIST_FILE%" (
    echo Module list file not found: %MODULES_LIST_FILE%
    exit /b 1
)

REM Path to CMock script (common for all modules)
set "CMOCK_PATH=%PROJECT_ROOT%\Tools\Unit_Testing\Cmock\lib\cmock.rb"

REM Loop through each module path listed in the module list file
for /f "delims=" %%m in (%MODULES_LIST_FILE%) do (
    set "MODULE_PATH=%%m"
    set "YML_CONFIG=%PROJECT_ROOT%\!MODULE_PATH!\gcc.yml"
    set "HEADERS_FILE=%PROJECT_ROOT%\!MODULE_PATH!\mock_headers.txt"

    REM Check if mock_headers.txt exists in the module path
    if not exist "!HEADERS_FILE!" (
        echo Skipping !MODULE_PATH! - mock_headers.txt not found
        echo.
    ) else (
        REM Read the headers from the mock headers file and build the list
        set "HEADERS="
        for /f "delims=" %%h in (!HEADERS_FILE!) do (
            set "HEADERS=!HEADERS! %PROJECT_ROOT%\%%h"
        )

        REM Run the ruby command with the collected headers
        echo Generating mocks for module: !MODULE_PATH! using headers:
        echo !HEADERS!
        ruby "!CMOCK_PATH!" -o"!YML_CONFIG!" !HEADERS!
        if errorlevel 1 (
            echo CMock generation failed for !MODULE_PATH!
            exit /b 1
        )

        echo CMock generation succeeded for module: !MODULE_PATH!
        echo.
    )
)

echo Mock generation completed for all modules in the list.
exit /b 0
