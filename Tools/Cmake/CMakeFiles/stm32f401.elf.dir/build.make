# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Programy\ARM_toolchain\Cmake\bin\cmake.exe

# The command to remove a file.
RM = D:\Programy\ARM_toolchain\Cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Self_development\stm32f401\Tools\Cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Self_development\stm32f401\Tools\Cmake

# Include any dependencies generated for this target.
include CMakeFiles/stm32f401.elf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/stm32f401.elf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/stm32f401.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stm32f401.elf.dir/flags.make

CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/02_Srv/main.c.obj: CMakeFiles/stm32f401.elf.dir/flags.make
CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/02_Srv/main.c.obj: D:/Self_development/stm32f401/Sw_Components/02_Srv/main.c
CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/02_Srv/main.c.obj: CMakeFiles/stm32f401.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Self_development\stm32f401\Tools\Cmake\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/02_Srv/main.c.obj"
	D:\Programy\ARM_toolchain\10_2021_10\bin\arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/02_Srv/main.c.obj -MF CMakeFiles\stm32f401.elf.dir\D_\Self_development\stm32f401\Sw_Components\02_Srv\main.c.obj.d -o CMakeFiles\stm32f401.elf.dir\D_\Self_development\stm32f401\Sw_Components\02_Srv\main.c.obj -c D:\Self_development\stm32f401\Sw_Components\02_Srv\main.c

CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/02_Srv/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/02_Srv/main.c.i"
	D:\Programy\ARM_toolchain\10_2021_10\bin\arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Self_development\stm32f401\Sw_Components\02_Srv\main.c > CMakeFiles\stm32f401.elf.dir\D_\Self_development\stm32f401\Sw_Components\02_Srv\main.c.i

CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/02_Srv/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/02_Srv/main.c.s"
	D:\Programy\ARM_toolchain\10_2021_10\bin\arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Self_development\stm32f401\Sw_Components\02_Srv\main.c -o CMakeFiles\stm32f401.elf.dir\D_\Self_development\stm32f401\Sw_Components\02_Srv\main.c.s

CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/core_init/system_stm32f4xx.c.obj: CMakeFiles/stm32f401.elf.dir/flags.make
CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/core_init/system_stm32f4xx.c.obj: D:/Self_development/stm32f401/Sw_Components/05_Mcu/core_init/system_stm32f4xx.c
CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/core_init/system_stm32f4xx.c.obj: CMakeFiles/stm32f401.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Self_development\stm32f401\Tools\Cmake\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/core_init/system_stm32f4xx.c.obj"
	D:\Programy\ARM_toolchain\10_2021_10\bin\arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/core_init/system_stm32f4xx.c.obj -MF CMakeFiles\stm32f401.elf.dir\D_\Self_development\stm32f401\Sw_Components\05_Mcu\core_init\system_stm32f4xx.c.obj.d -o CMakeFiles\stm32f401.elf.dir\D_\Self_development\stm32f401\Sw_Components\05_Mcu\core_init\system_stm32f4xx.c.obj -c D:\Self_development\stm32f401\Sw_Components\05_Mcu\core_init\system_stm32f4xx.c

CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/core_init/system_stm32f4xx.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/core_init/system_stm32f4xx.c.i"
	D:\Programy\ARM_toolchain\10_2021_10\bin\arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Self_development\stm32f401\Sw_Components\05_Mcu\core_init\system_stm32f4xx.c > CMakeFiles\stm32f401.elf.dir\D_\Self_development\stm32f401\Sw_Components\05_Mcu\core_init\system_stm32f4xx.c.i

CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/core_init/system_stm32f4xx.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/core_init/system_stm32f4xx.c.s"
	D:\Programy\ARM_toolchain\10_2021_10\bin\arm-none-eabi-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Self_development\stm32f401\Sw_Components\05_Mcu\core_init\system_stm32f4xx.c -o CMakeFiles\stm32f401.elf.dir\D_\Self_development\stm32f401\Sw_Components\05_Mcu\core_init\system_stm32f4xx.c.s

CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/startup/startup_stm32f401ccux.s.obj: CMakeFiles/stm32f401.elf.dir/flags.make
CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/startup/startup_stm32f401ccux.s.obj: D:/Self_development/stm32f401/Sw_Components/05_Mcu/startup/startup_stm32f401ccux.s
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Self_development\stm32f401\Tools\Cmake\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building ASM object CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/startup/startup_stm32f401ccux.s.obj"
	D:\Programy\ARM_toolchain\10_2021_10\bin\arm-none-eabi-gcc.exe $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles\stm32f401.elf.dir\D_\Self_development\stm32f401\Sw_Components\05_Mcu\startup\startup_stm32f401ccux.s.obj -c D:\Self_development\stm32f401\Sw_Components\05_Mcu\startup\startup_stm32f401ccux.s

CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/startup/startup_stm32f401ccux.s.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing ASM source to CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/startup/startup_stm32f401ccux.s.i"
	D:\Programy\ARM_toolchain\10_2021_10\bin\arm-none-eabi-gcc.exe $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -E D:\Self_development\stm32f401\Sw_Components\05_Mcu\startup\startup_stm32f401ccux.s > CMakeFiles\stm32f401.elf.dir\D_\Self_development\stm32f401\Sw_Components\05_Mcu\startup\startup_stm32f401ccux.s.i

CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/startup/startup_stm32f401ccux.s.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling ASM source to assembly CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/startup/startup_stm32f401ccux.s.s"
	D:\Programy\ARM_toolchain\10_2021_10\bin\arm-none-eabi-gcc.exe $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -S D:\Self_development\stm32f401\Sw_Components\05_Mcu\startup\startup_stm32f401ccux.s -o CMakeFiles\stm32f401.elf.dir\D_\Self_development\stm32f401\Sw_Components\05_Mcu\startup\startup_stm32f401ccux.s.s

# Object files for target stm32f401.elf
stm32f401_elf_OBJECTS = \
"CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/02_Srv/main.c.obj" \
"CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/core_init/system_stm32f4xx.c.obj" \
"CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/startup/startup_stm32f401ccux.s.obj"

# External object files for target stm32f401.elf
stm32f401_elf_EXTERNAL_OBJECTS =

stm32f401.elf: CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/02_Srv/main.c.obj
stm32f401.elf: CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/core_init/system_stm32f4xx.c.obj
stm32f401.elf: CMakeFiles/stm32f401.elf.dir/D_/Self_development/stm32f401/Sw_Components/05_Mcu/startup/startup_stm32f401ccux.s.obj
stm32f401.elf: CMakeFiles/stm32f401.elf.dir/build.make
stm32f401.elf: CMakeFiles/stm32f401.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Self_development\stm32f401\Tools\Cmake\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable stm32f401.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\stm32f401.elf.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stm32f401.elf.dir/build: stm32f401.elf
.PHONY : CMakeFiles/stm32f401.elf.dir/build

CMakeFiles/stm32f401.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\stm32f401.elf.dir\cmake_clean.cmake
.PHONY : CMakeFiles/stm32f401.elf.dir/clean

CMakeFiles/stm32f401.elf.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Self_development\stm32f401\Tools\Cmake D:\Self_development\stm32f401\Tools\Cmake D:\Self_development\stm32f401\Tools\Cmake D:\Self_development\stm32f401\Tools\Cmake D:\Self_development\stm32f401\Tools\Cmake\CMakeFiles\stm32f401.elf.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/stm32f401.elf.dir/depend

