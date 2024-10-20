## Need to install:
    1) Compiler and related tools
       - arm-none-eabi
       - make
       - cmake
       - mingw - required for Cmake generation
       - ruby - required for CMock 
    2) Open OCD

To enable VS Code task execution configure paths in 'settings.json' file.

The project and automation scripts are trimmed for Windows environment. ⊞

## Hardware Setup
![Basic_Setup](https://github.com/inpgbburda/Stm32f401/assets/49471138/361be77b-3889-4240-b91b-b38e69d017e0)

## Unit Tests Setup
To add new UT module append its path into 'ut_modules_config.txt' file.

Unit tests are added inside every module directory. There need to be the follwing structure, to allow automation script work propperly:

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
To achieve generation of mocks, add path of mocked header into 'mocked_headers.txt' file.
