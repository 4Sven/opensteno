cmake_minimum_required(VERSION 2.8)
set(EXE_NAME opensteno)
project(${EXE_NAME})

#add link_directories because w/o I can't build project on my mac
link_directories(/usr/local/lib)

if(NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type")
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_executable(${PROJECT_NAME}
source/Steno.cpp
)

#INCLUDE(FindPkgConfig)
#PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
#INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})



find_package(PkgConfig REQUIRED)

pkg_search_module(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIRS})
set(OPENSTENO_LIBRARIES ${SDL2_LIBRARIES})

pkg_search_module(GTK3 REQUIRED gtk3+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
list(APPEND OPENSTENO_LIBRARY ${GTK3_LIBRARIES})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OPENSTENO_LIBRARIES})
