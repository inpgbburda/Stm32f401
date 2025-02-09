project("motor_ctrl_UT" C)
cmake_minimum_required(VERSION 3.0)

SET(UNITY_RLV_PATH 
    ../../../../Tools/Unit_Testing/Unity_Framework
)

SET(CMOCK_RLV_PATH 
    ../../../../Tools/Unit_Testing/Cmock
)

include_directories(
    mocks/
    mocks/portable/GCC/ARM_CM4F/
    ../
    ${CMAKE_CURRENT_SOURCE_DIR}/${UNITY_RLV_PATH}/Unity/src
    ${CMAKE_CURRENT_SOURCE_DIR}/${CMOCK_RLV_PATH}/src
    ../../../../Sw_Components/02_Srv/Os/FreeRTOS_UT
    ../../../../Sw_Components/02_Srv/Os/FreeRTOS/Config/
    ../../../../Sw_Components/04_Drv/pwm/
    ../../../../Sw_Components/05_Mcu/stm32/
    ../../../../Sw_Components/05_Mcu/CMSIS/
)

add_executable(${CMAKE_PROJECT_NAME}
    motor_ctrl_UT.c
    ../motor_ctrl.c
    mocks/pwm.c
    mocks/queue.c
    ../../../../Sw_Components/04_Drv/pwm/pwm_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/${UNITY_RLV_PATH}/Unity/src/unity.c
    ${CMAKE_CURRENT_SOURCE_DIR}/${CMOCK_RLV_PATH}/src/cmock.c
)

target_link_libraries(${CMAKE_PROJECT_NAME}

)