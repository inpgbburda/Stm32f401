## About
This is the **AuxUnit** of the **FlyMatic** drone project.\
Click here to read more: [Flymatic_HomePage](https://inpgbburda.github.io/FlyMatic/)

## Need to install:
    1) Compiler and related tools
       - arm-none-eabi
       - make
       - cmake
       - mingw - required for Cmake generation and compilation
       - ruby - required for CMock 
    2) Open OCD
    3) Code formatter
        - LLVM Snapshot 
To enable VS Code task execution configure paths in `settings.json` file.\
The project and automation scripts are trimmed for Windows environment. ⊞\
[LLVM_Snapshot_link](https://llvm.org/builds/)

## Hardware Setup
![Basic_Setup](https://github.com/inpgbburda/Stm32f401/assets/49471138/361be77b-3889-4240-b91b-b38e69d017e0)

## Unit Tests Setup
To <ins> add new UT module </ins> append its path into `ut_modules_config.txt` file.

Unit tests are added inside every module directory. There need to be the following structure, to allow automation script work propperly:

```text
<funcional_module>
 |
 +-- <funcional_module>_UT
 |  |  
 |  +-- mocks(optional)
 |  +-- gcc.yml(optional)
 |  +-- mock_headers.txt(optional)
 |  +-- Output_UT
 |  +-- CmakeLists.txt
 |  +-- CmakePresets.json
 |  +-- <funcional_module>_UT.c
 ```
To achieve generation of mocks, add path of mocked header into `mocked_headers.txt` file.

The `rtos_types_UT.h` file is used across the project, to provide lightweight and hw independent types of RTOS functions. It allows mocks used with RTOS api compile properly.
It **must be updated** together with Os updates.


## Code formatter
Formatter uses the `.clang-format` file as a configuration.\
It can be used in VS code by `Shift + Alt + F`.
