project("Motor_Ctrl_Ut" C)
cmake_minimum_required(VERSION 3.0)

SET(UNITY_RLV_PATH 
    ../../../../Tools/Unit_Testing/Unity_Framework
)

SET(CMOCK_RLV_PATH 
    ../../../../Tools/Unit_Testing/Cmock
)

include_directories(
    mocks/
    ../
    ${CMAKE_CURRENT_SOURCE_DIR}/${UNITY_RLV_PATH}/Unity/src
    ${CMAKE_CURRENT_SOURCE_DIR}/${CMOCK_RLV_PATH}/src
)

add_executable(${CMAKE_PROJECT_NAME}
    motor_ctrl_UT.c
    ../motor_ctrl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/${UNITY_RLV_PATH}/Unity/src/unity.c
    ${CMAKE_CURRENT_SOURCE_DIR}/${CMOCK_RLV_PATH}/src/cmock.c
)

target_link_libraries(${CMAKE_PROJECT_NAME}

)