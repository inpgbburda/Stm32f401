@echo off
setlocal

:: Check if CMake path argument is provided
if "%~1"=="" (
    echo Usage: %~nx0 ^<cmake_path^>
    echo Example: %~nx0 C:\path\to\cmake.exe
    exit /b 1
)

:: Set the CMake path from the first argument
set "cmake_path=%~1"

:: Define the list of UT module paths
set "ut_modules=Sw_Components\01_App\MotorCtrl\motor_ctrl_UT"
set "ut_modules=%ut_modules%=Sw_Components\04_Drv\spi\spi_UT"
set "ut_modules=%ut_modules%=Sw_Components\04_Drv\pwm\pwm_UT"
:: Add more module paths here...

:: Set the CMake preset
set "cmake_preset=default"

:: Loop through each UT module and run CMake configuration
for %%m in (%ut_modules%) do (
    echo Configuring CMake for %%m...

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
