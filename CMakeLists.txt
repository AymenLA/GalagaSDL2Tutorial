cmake_minimum_required (VERSION 3.18)

project (GalagaSDL2Tutorial)

# The version number.
set (GalagaSDL2Tutorial_VERSION_MAJOR 1)
set (GalagaSDL2Tutorial_VERSION_MINOR 0)

# project main directory
set (GALAGA_APPLICATION_DIR ${CMAKE_CURRENT_SOURCE_DIR}/GalagaSDL2)

# externals directory
set (EXTERNAL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/External)
set (GOOGLETEST_DIR ${EXTERNAL_DIR}/googletest)
set (BUILDTOOLS_DIR ${EXTERNAL_DIR}/buildtools)

# source files : main
set (GALAGASDL2_MAIN_SOURCE_FILE 
    ${GALAGA_APPLICATION_DIR}/main.cpp
    )

# source files : Graphics
set (GALAGASDL2_GRAPHICS_SOURCE_FILES
    ${GALAGA_APPLICATION_DIR}/Graphics/src/Graphics.cpp
    )

# source files : GameManager
set (GALAGASDL2_GAMEMANAGER_SOURCE_FILES
    ${GALAGA_APPLICATION_DIR}/GameManager/src/GameManager.cpp
    )

# Header files : ALL directories
set (GALAGASDL2_INCLUDE_DIRS
    ${GALAGA_APPLICATION_DIR}/Graphics/include
    ${GALAGA_APPLICATION_DIR}/GameManager/include
    )

# constants include directory
set (CONSTANTS_INCLUDE_DIR 
    ${GALAGA_APPLICATION_DIR}/Constants/include
    )

# use the provided cmake files for SDL2
list (APPEND CMAKE_PREFIX_PATH ${BUILDTOOLS_DIR}/cmake/SDL2)
set (CMAKE_MODULE_PATH FindSDL2.cmake FindSDL2_image.cmake FindSDL2_ttf.cmake)

find_package (SDL2 REQUIRED)
find_package (SDL2_ttf REQUIRED)
find_package (SDL2_image REQUIRED)
find_package (SDL2_mixer REQUIRED)
find_package (SDL2_gfx REQUIRED)
find_package (SDL2_net REQUIRED)

# SDL2 specific include directories
set (SDL2_SPECIFIC_INCLUDE_DIRS 
    ${SDL2_INCLUDE_DIRS} 
    ${SDL2IMAGE_INCLUDE_DIRS} 
    ${SDL2TTF_INCLUDE_DIRS}
)

# additional includes - NOT USED
include_directories(
                    ${SDL2_SPECIFIC_INCLUDE_DIRS}
                    ${CONSTANTS_INCLUDE_DIR}
                    ${GALAGASDL2_INCLUDE_DIRS}
                    )

# main file will be the master of the opration
set(TARGET_SOURCES_FILES 
    ${GALAGASDL2_MAIN_SOURCE_FILE}
    ${GALAGASDL2_GRAPHICS_SOURCE_FILES}
    ${GALAGASDL2_GAMEMANAGER_SOURCE_FILES}
    )


set(CMAKE_BUILD_TYPE Debug)

add_executable(${CMAKE_PROJECT_NAME} 
                ${TARGET_SOURCES_FILES} 
                ${TARGET_HEADER_FILES}
                )

target_link_libraries(
        ${CMAKE_PROJECT_NAME} 
        ${SDL2_LIBRARIES} 
        ${SDL2IMAGE_LIBRARIES} 
        ${SDL2TTF_LIBRARIES}
        ${SDL2GFX_LIBRARIES} 
        ${SDL2MIXER_LIBRARIES}
        ${SDL2NET_LIBRARIES}
)