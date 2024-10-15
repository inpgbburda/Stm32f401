@echo off
REM Check if the project root was passed as the first argument
if "%~1"=="" (
    echo No project root was passed.
    exit /b 1
)

REM Use the first argument as the project root
set "PROJECT_ROOT=%~1"

REM Define paths relative to the project root
set "CMOCK_PATH=%PROJECT_ROOT%\Tools\Unit_Testing\Cmock\lib\cmock.rb"
set "YML_CONFIG=%PROJECT_ROOT%\Sw_Components\01_App\MotorCtrl\motor_ctrl_UT\gcc.yml"

REM List of header files to include (just add more lines for new files)
set HEADERS=%PROJECT_ROOT%\Sw_Components\04_Drv\pwm\pwm.h
@REM set HEADERS=%HEADERS% %PROJECT_ROOT%\Sw_Components\04_Drv\timer\timer.h
@REM set HEADERS=%HEADERS% %PROJECT_ROOT%Sw_Components\01_App\MotorCtrl\motor_ctrl.h

REM Run the ruby command with all headers
ruby "%CMOCK_PATH%" -o"%YML_CONFIG%" %HEADERS%
