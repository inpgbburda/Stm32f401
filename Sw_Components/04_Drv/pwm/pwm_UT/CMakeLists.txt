project("Pwm_UT" C)
cmake_minimum_required(VERSION 3.0)

include(CTest)

SET(UNITY_RLV_PATH 
    ../../../../Tools/Unit_Testing/Unity_Framework
)

include_directories(
    ../
    ../../../../Sw_Components/05_Mcu/CMSIS/
    ../../../../Sw_Components/05_Mcu/stm32/
    ${CMAKE_CURRENT_SOURCE_DIR}/${UNITY_RLV_PATH}/Unity/src
)

add_executable(${CMAKE_PROJECT_NAME}
    pwm_UT.c
    ../pwm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/${UNITY_RLV_PATH}/Unity/src/unity.c
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    # C:/Users/bartl/Documents/Projekty/black_pill/Stm32f401/Tools/Unit_Testing/Unity_Framework/Unity/libs/libUnity.a
)