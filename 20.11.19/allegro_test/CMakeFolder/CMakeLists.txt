
cmake_minimum_required(VERSION 3.16)

project(test VERSION 0.1 LANGUAGES C)

set(PARENT_DIR "${PROJECT_SOURCE_DIR}/../")

set(SOURCES "${PARENT_DIR}/sources/main.c")

add_executable(${PROJECT_NAME} ${SOURCES})

include_directories("E:/c/my_libs/allegro/include")

set(EXECUTABLE_OUTPUT_PATH "${PARENT_DIR}/bin")

#-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

set_target_properties(${PROJECT_NAME} PROPERTIES C_STANDARD 11)

#-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

set(ALLEGRO_DIR "E:/c/my_libs/my_allegro")

# from "allegro\lib"
#set(LIB_NAMES "liballegro.dll.a" "liballegro-debug.dll.a"
#            "liballegro_acodec.dll.a" "liballegro_acodec-debug.dll.a"
#
#            "liballegro_audio.dll.a" "liballegro_audio-debug.dll.a"
#            "liballegro_color.dll.a" "liballegro_color-debug.dll.a"
#            "liballegro_dialog.dll.a" "liballegro_dialog-debug.dll.a"
#
#            "liballegro_font.dll.a" "liballegro_font-debug.dll.a"
#            "liballegro_image.dll.a" "liballegro_image-debug.dll.a"
#            "liballegro_main.dll.a" "liballegro_main-debug.dll.a"
#
#            "liballegro_memfile.dll.a" "liballegro_memfile-debug.dll.a" 
#            "liballegro_monolith.dll.a" "liballegro_monolith-debug.dll.a" 
#            "liballegro_physfs.dll.a" "liballegro_physfs-debug.dll.a"
#
#            "liballegro_primitives.dll.a" "liballegro_primitives-debug.dll.a"
#            "liballegro_ttf.dll.a" "liballegro_ttf-debug.dll.a" 
#            "liballegro_video.dll.a" "liballegro_video-debug.dll.a")

#set(BIN_NAMES "allegro_acodec-5.2.dll" "allegro_acodec-debug-5.2.dll"
#            "allegro_audio-5.2.dll" "allegro_audio-debug-5.2.dll"
#            "allegro_color-5.2.dll" "allegro_color-debug-5.2.dll"
#            
#            "allegro_dialog-5.2.dll" "allegro_dialog-debug-5.2.dll"
#            "allegro_font-5.2.dll" "allegro_font-debug-5.2.dll"
#            "allegro_image-5.2.dll" "allegro_image-debug-5.2.dll"
#            
#            "allegro_main-5.2.dll" "allegro_main-debug-5.2.dll"
#            "allegro_memfile-5.2.dll" "allegro_memfile-debug-5.2.dll"
#            "allegro_monolith-5.2.dll" "allegro_monolith-debug-5.2.dll"
#            
#            "allegro_physfs-5.2.dll" "allegro_physfs-debug-5.2.dll"
#            "allegro_primitives-5.2.dll" "allegro_primitives-debug-5.2.dll"
#            "allegro_ttf-5.2.dll" "allegro_ttf-debug-5.2.dll"
#            
#            "allegro_video-5.2.dll" "allegro_video-debug-5.2.dll"
#            "allegro-5.2.dll" "allegro-debug-5.2.dll")

#set(BIN_NAMES "allegro_acodec-5.2" "allegro_acodec-debug-5.2"
#            "allegro_audio-5.2" "allegro_audio-debug-5.2"
#            "allegro_color-5.2" "allegro_color-debug-5.2"
#            
#            "allegro_dialog-5.2" "allegro_dialog-debug-5.2"
#            "allegro_font-5.2" "allegro_font-debug-5.2"
#            "allegro_image-5.2" "allegro_image-debug-5.2"
#            
#            "allegro_main-5.2" "allegro_main-debug-5.2"
#            "allegro_memfile-5.2" "allegro_memfile-debug-5.2"
#            "allegro_monolith-5.2" "allegro_monolith-debug-5.2"
#            
#            "allegro_physfs-5.2" "allegro_physfs-debug-5.2"
#            "allegro_primitives-5.2" "allegro_primitives-debug-5.2"
#            "allegro_ttf-5.2" "allegro_ttf-debug-5.2"
#            
#            "allegro_video-5.2" "allegro_video-debug-5.2"
#            "allegro-5.2" "allegro-debug-5.2")

set(LIB_NAMES "allegro.lib" "allegro-debug.lib"
            "allegro_acodec.lib" "allegro_acodec-debug.lib"

            "allegro_audio.lib" "allegro_audio-debug.lib"
            "allegro_color.lib" "allegro_color-debug.lib"
            "allegro_dialog.lib" "allegro_dialog-debug.lib"

            "allegro_font.lib" "allegro_font-debug.lib"
            "allegro_image.lib" "allegro_image-debug.lib"
            "allegro_main.lib" "allegro_main-debug.lib"

            "allegro_memfile.lib" "allegro_memfile-debug.lib" 
            "allegro_monolith-static.lib"
            "allegro_physfs.lib" "allegro_physfs-debug.lib"

            "allegro_primitives.lib" "allegro_primitives-debug.lib"
            "allegro_ttf.lib" "allegro_ttf-debug.lib"
            "allegro_video.lib" "allegro_video-debug.lib"
            )

foreach(LIB_NAME ${LIB_NAMES})
    message("${ALLEGRO_DIR}/lib/${LIB_NAME}")
    target_link_libraries(${PROJECT_NAME} "${ALLEGRO_DIR}/lib/${LIB_NAME}")
endforeach()