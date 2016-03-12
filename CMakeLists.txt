cmake_minimum_required(VERSION 3.5)
set(EXE_NAME opensteno)
project(${EXE_NAME})

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

add_executable(${PROJECT_NAME}
source/main.cpp
source/Steno.cpp
source/definitions.hpp
source/definitions.cpp
)


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

pkg_search_module(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIRS})
set(OPENSTENO_LIBRARIES ${SDL2_LIBRARIES})

#list(APPEND OPENSTENO_LIBRARIES )


if (UnitTestPlusPlus_FOUND)
    enable_testing()
    add_subdirectory(tests)
endif ()

if (CMAKE_VERSION VERSION_GREATER 2.8.5)
    include(FeatureSummary)
    feature_summary(WHAT ALL)
endif ()

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OPENSTENO_LIBRARIES})
