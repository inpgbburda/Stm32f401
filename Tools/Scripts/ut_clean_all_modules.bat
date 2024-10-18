@echo off
setlocal enabledelayedexpansion

:: Check if make path and config file arguments are provided
if "%~1"=="" (
    echo Usage: %~nx0 ^<make_path^> ^<module_config_path^>
    echo Example: %~nx0 C:\path\to\make.exe ut_modules_config.txt
    exit /b 1
)

if "%~2"=="" (
    echo Please provide the path to the module configuration file.
    exit /b 1
)

:: Set the make path and config file from arguments
set "make_path=%~1"
set "config_file=%~2"

:: Read the module paths from the configuration file
for /f "usebackq tokens=*" %%m in ("%config_file%") do (
    echo Cleaning makefiles for: %%m

    :: Check if Output_UT folder exists in the module directory
    if exist "%%m\Output_UT" (
        pushd "%%m\Output_UT"
        
        :: Run make clean command
        "%make_path%" clean
        if errorlevel 1 (
            echo Clean failed for: %%m\Output_UT
            echo Command executed: "%make_path%" clean
            popd
            exit /b 1
        )
        
        :: Go back to the original directory
        popd
    ) else (
        echo Output_UT folder does not exist for %%m, skipping...
    )
)

echo Cleaning completed for all UT modules.
exit /b
