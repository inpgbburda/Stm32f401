cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE Toolchain-arm-gcc.cmake)

# Allow assembler
enable_language(ASM)

SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)
project(stm32f401)

set(REL_PATH ../../)

set(INCLUDE_DIRS
    ${REL_PATH}Sw_Components/04_Drv/pwm
    ${REL_PATH}Sw_Components/05_Mcu
    ${REL_PATH}Sw_Components/05_Mcu/stm32
    ${REL_PATH}Sw_Components/05_Mcu/CMSIS
    ${REL_PATH}Sw_Components/05_Mcu/core_init
    ${REL_PATH}Sw_Components/05_Mcu/startup
)

set(CPP_SRCS
	 
)

set(C_SRCS
    ${REL_PATH}Sw_Components/02_Srv/main.c
    ${REL_PATH}Sw_Components/04_Drv/pwm/pwm.c
    ${REL_PATH}SW_Components/05_Mcu/core_init/system_stm32f4xx.c
    # ${REL_PATH}Sw_Components/05_Mcu/startup/vectors.c
)

set(ASM_SRCS
    ${REL_PATH}Sw_Components/05_Mcu/startup/startup_stm32f401ccux.s
)

set(GLOBAL_DEFINES

)

set(LINKED_LIBS

)

link_directories(

)

include_directories(${INCLUDE_DIRS})
add_definitions(${GLOBAL_DEFINES})

include(compiler_flags.cmake)

# Static Analisys:
# option(STATIC_ANALYSIS "Build with static analysis" OFF)
# if (STATIC_ANALYSIS)
#     include(static-analysis.cmake)
# endif()

# generate elf file using macro "add_arm_executable"
add_arm_executable(${CMAKE_PROJECT_NAME} ${CPP_SRCS} ${C_SRCS} ${ASM_SRCS})

arm_link_libraries(${CMAKE_PROJECT_NAME} ${LINKED_LIBS})

#print size of binary
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
        COMMAND arm-none-eabi-size --format=berkeley ${CMAKE_PROJECT_NAME}.elf
        COMMENT "Invoking: Cross ARM GNU Print Size \n")