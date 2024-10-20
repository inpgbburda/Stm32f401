@echo off
setlocal

:: Check if the make path and module path are provided
if "%~1"=="" (
    echo Usage: %~nx0 ^<make_path^> ^<module_path^>
    echo Example: %~nx0 C:\path\to\make.exe C:\path\to\module
    exit /b 1
)

if "%~2"=="" (
    echo Please provide the path to the module.
    exit /b 1
)

:: Set the make path and module path from arguments
set "make_path=%~1"
set "module_path=%~2"
set "exe_name=%~n2.exe"   :: Automatically name the executable based on the module directory name (e.g., Pwm_Ut.exe)

:: Navigate to the module directory's Output_UT folder
set "output_dir=%module_path%\Output_UT"
if not exist "%output_dir%" (
    echo Output_UT folder does not exist in %module_path%, creating it...
    mkdir "%output_dir%"
)

pushd "%output_dir%" || (
    echo Failed to navigate to %output_dir%
    exit /b 1
)

:: Run make all (build step)
echo Building module in %output_dir%...
"%make_path%" all
if errorlevel 1 (
    echo Build failed for %module_path%.
    popd
    exit /b 1
)

:: Run the generated executable (run step)
echo Running executable: %exe_name%...
if exist "%exe_name%" (
    "%exe_name%"
    if errorlevel 1 (
        echo Test execution failed for %exe_name%.
        popd
        exit /b 1
    )
) else (
    echo Executable %exe_name% not found.
    popd
    exit /b 1
)

:: Return to the original directory
popd
echo Build and run completed for module %module_path%.
exit /b 0
