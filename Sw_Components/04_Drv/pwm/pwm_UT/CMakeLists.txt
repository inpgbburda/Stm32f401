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
# Mocking - to be fixed later

# # Define the list of header files to mock
# set(MOCKED_HEADER ${CMAKE_CURRENT_BINARY_DIR}/../pwm.h)

# # Define the CMOCK_DIR variable
# set(CMOCK_DIR D:/Self_development/stm32f401/Tools/Unit_Testing/Unity_Framework/cmock)

# Generate the mock files using the create_mock.rb script
# foreach(header ${MOCKED_HEADER})
#     add_custom_command(
#         OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${header}
#         COMMAND CMOCK_DIR=${CMOCK_DIR} ruby unit-tests/create_mock.rb ${CMAKE_CURRENT_BINARY_DIR}/${header}
#         DEPENDS ${header}
#     )
# endforeach()

# # Add the mock files to the project's source files
# set(SOURCE_FILES main.cpp ${MOCKED_HEADER})

set(MOCKED_HEADER D:/Self_development/stm32f401/Sw_Components/04_Drv/pwm/pwm.h ) #provide the path to header


get_filename_component(MOCKED_HEADER_NAME ${MOCKED_HEADER} NAME)
set(MOCK_OUTPUT_DIR ${CMAKE_BINARY_DIR}/build/cmock)
set(MOCK_OUTPUT_FILE ${MOCK_OUTPUT_DIR}/${MOCKED_HEADER_NAME})

set(ENV{CMOCK_DIR} D:/Self_development/stm32f401/Tools/Unit_Testing/Unity_Framework/cmock)
add_custom_command(
    OUTPUT ${MOCK_OUTPUT_FILE}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${MOCK_OUTPUT_DIR}
    COMMAND ruby D:/Self_development/stm32f401/Tools/Unit_Testing/Unity_Framework/cmock/scripts/create_makefile.rb D:/Self_development/stm32f401/Sw_Components/04_Drv/pwm/pwm.h
    # DEPENDS ${MOCKED_HEADER}
)

add_custom_target( create_mock DEPENDS ${MOCK_OUTPUT_FILE} )