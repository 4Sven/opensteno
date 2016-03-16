cmake_minimum_required(VERSION 3.5)
set(EXE_NAME opensteno)
project(${EXE_NAME})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR})

cmake_policy(SET CMP0004 OLD)

set(HEADERS
source/gui.hpp
)

set(SOURCES
source/main.cpp
#source/Steno.cpp
#source/definitions.hpp
#source/definitions.cpp
#source/gui.cpp
)

#add Xcode specific settings
if(CMAKE_GENERATOR STREQUAL Xcode)
    #add link_directories because w/o I can't build project on my mac
    link_directories(/usr/local/lib)
    #set testability setting for Xcode
    set(CMAKE_XCODE_ATTRIBUTE_ENABLE_TESTABILITY[variant=Debug] "YES")
endif()

if(NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type")
endif()


list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../doc
        COMMENT "Generating API documentation with Doxygen" VERBATIM
    )
endif(DOXYGEN_FOUND)

find_package(PkgConfig REQUIRED)

#pkg_search_module(SDL2 REQUIRED sdl2)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
set(OPENSTENO_LIBRARIES ${SDL2_LIBRARIES})

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${QT_INCLUDE_DIR})
list(APPEND OPENSTENO_LIBRARIES ${QT_LIBRARIES})
qt4_wrap_cpp(HEADERS_MOC ${HEADERS})
qt4_wrap_ui(GUI_UI_H source/opensteno.ui)

#pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
#include_directories(${GTK3_INCLUDE_DIRS})
#list(APPEND OPENSTENO_LIBRARIES ${GTK3_LIBRARIES})

if (UnitTestPlusPlus_FOUND)
    enable_testing()
    add_subdirectory(tests)
endif ()

add_executable(${PROJECT_NAME}
${HEADERS_MOC}
${SOURCES}
${GUI_UI_H}
)

if (CMAKE_VERSION VERSION_GREATER 2.8.5)
    include(FeatureSummary)
    feature_summary(WHAT ALL)
endif ()

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OPENSTENO_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/build)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME}${BUILD_POSTFIX})
