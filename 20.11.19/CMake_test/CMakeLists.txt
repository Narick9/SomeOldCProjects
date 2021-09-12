
# комментарий

cmake_minimum_required(VERSION 3.16)

project(project_test VERSION 0.1 LANGUAGES C)

message("########################################start")


message("SCRIPT_VAR before include MyScripts.cmake: [${SCRIPT_VAR}]")
include(MyScripts.cmake)
message("SCRIPT_VAR after include MyScripts.cmake: [${SCRIPT_VAR}]")
message("\n\n")


add_executable(${PROJECT_NAME} "main.c")
message("add_executable 'project_test' pass")
message("\n\n")


add_library(lib STATIC "lib.c")
message("add_library 'lib' pass")
message("\n\n")


#target_sources(<target> <sourses..>)


set(RUNTIME_OUTPUT_DIRECTORY "E:\\")
set(ARCHIVE_OUTPUT_DIRECTORY "E:\\")
message("ERROR:\t set ..._OUTPUT_... pass")
message("\n\n")


message("PROJECT_NAME is [${PROJECT_NAME}]")
message("\n\n")


target_link_libraries(${PROJECT_NAME} lib)
message("target_link_libraries '${PROJECT_NAME} lib' pass")
message("\n\n")


set_target_properties(${PROJECT_NAME} PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)
message("set_target_properties ... pass")
message("\n\n")


get_target_property(C_STD ${PROJECT_NAME} C_STANDARD)
message("C_STANDARD is equal [${C_STD}]")
message("\n\n")


if (TARGET project_test)
    message("project_test is defined!")
else()
    message("project_test is not defined!")
endif()
message("\n\n")


#add_subdirectory(<subproject> [<his directory>])


#find_package(GSL 2.0 (-версия) REQUIRED(/QUIT - опции) )   модульное подключение, т.е. ищет файл FindGSL.cmake
#target_link_libraries(GSL::gsl)    GSL::gsl - инкапсулирует путь к уже скомпилированному GSL
#target_include_directories(${PROJECT_NAME} ${GSL_INCLUDE_DIRS})    ${GSL_INCLUDE_DIRS} - пример 
#                                                                   импортирования настроек пакета
#if(GSL_FOUND)
#    message("GSL was succesfully connected")
#else()
#    message("an ERROR occured while GSL connecting")
#endif()


install(TARGETS ${PROJECT_NAME} lib DESTINATION "E:\\")
install(DIRECTORY "TestFolder" DESTINATION "E:\\")
install(FILES file1.txt file2.txt DESTINATION "E:\\TestFolder")
message("install(...) pass")


message("########################################end")