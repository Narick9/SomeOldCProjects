
cmake_minimum_required(VERSION 3.16)

project(test VERSION 0.1 LANGUAGES C)

set(MAIN_DIR "${PROJECT_SOURCE_DIR}/..")
set(SOURCES "${MAIN_DIR}/sources/main.c")

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED OFF)

set(EXECUTABLE_OUTPUT_PATH "${MAIN_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${MAIN_DIR}/lib")

################################################################################

target_link_libraries(${PROJECT_NAME} "${MAIN_DIR}/bin/libmylib.dll")