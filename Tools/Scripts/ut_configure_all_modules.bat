@echo off
setlocal

:: Check if CMake path argument is provided
if "%~1"=="" (
    echo Usage: %~nx0 ^<cmake_path^> ^<path_to_config^>
    echo Example: %~nx0 C:\path\to\cmake.exe ut_modules_config.txt
    exit /b 1
)

:: Set the CMake path from the first argument
set "cmake_path=%~1"

:: Check if the config file argument is provided and exists
if "%~2"=="" (
    echo Please provide the path to the module configuration file.
    exit /b 1
)
if not exist "%~2" (
    echo Configuration file not found: %~2
    exit /b 1
)

:: Set the path to the configuration file
set "config_file=%~2"

:: Set the CMake preset
set "cmake_preset=default"

:: Read the module paths from the configuration file and process them
for /f "tokens=*" %%m in (%config_file%) do (
    echo Configuring CMake for %%m...

    :: Check if Output folder exists, create it if it doesn't
    if not exist "%%m\Output" (
        echo Creating Output folder in %%m...
        mkdir "%%m\Output"
    )

    :: Navigate to the module directory
    pushd %%m || (
        echo Failed to navigate to %%m
        exit /b 1
    )

    :: Run CMake with the preset
    "%cmake_path%" . --preset=%cmake_preset%
    if errorlevel 1 (
        echo CMake configuration failed for %%m
        popd
        exit /b 1
    )

    :: Return to the original directory
    popd
)

echo CMake configuration completed for all UT modules.
exit /b 0
