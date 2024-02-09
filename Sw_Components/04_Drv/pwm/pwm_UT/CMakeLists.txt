project("Pwm_Ut" C)
cmake_minimum_required(VERSION 3.0)

include(CTest)

SET(UNITY_RLV_PATH 
    ../../../../Tools/Unit_Testing/Unity_Framework
)

include_directories(
    ../
    ${CMAKE_CURRENT_SOURCE_DIR}/${UNITY_RLV_PATH}/Unity/src
)


include(CTest) # WTF?  

add_executable(${CMAKE_PROJECT_NAME}
    pwm_UT.c
    ../pwm.c
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/${UNITY_RLV_PATH}/Unity/libs/libUnity.a
)