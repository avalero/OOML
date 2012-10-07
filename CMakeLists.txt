cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0011 NEW)

# Project ID.
project(OOML CXX C)

set(OOML_TRUNK_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
# CMake Include path.
set(CMAKE_MODULE_PATH "${OOML_TRUNK_DIR}/cmake")


# Raw numeric version values.
set(OOML_VERSION_MAJOR "2")
set(OOML_VERSION_MINOR "0")
set(OOML_VERSION_PATCH "0")


# Check for SVN and get current revision
INCLUDE(${CMAKE_MODULE_PATH}/vcs-revision.cmake)
# Do not use revision information if I was unable to retrieve it
IF(NOT ${PROJECT_WC_REVISION} EQUAL 0)
	SET(OOML_VERSION ${OOML_VERSION_MAJOR}.${OOML_VERSION_MINOR}.${OOML_VERSION_PATCH}.${PROJECT_WC_REVISION})
	SET(OOML_VERSION_REVISION ${PROJECT_WC_REVISION})
ELSE(NOT ${PROJECT_WC_REVISION} EQUAL 0)
	SET(OOML_VERSION ${OOML_VERSION_MAJOR}.${OOML_VERSION_MINOR}.${OOML_VERSION_PATCH})
ENDIF(NOT ${PROJECT_WC_REVISION} EQUAL 0)


# Directory definitions.

set(OOML_SRC_DIR "${OOML_TRUNK_DIR}/src")
set(OOML_LIB_DIR "${OOML_TRUNK_DIR}/lib")
set(OOML_BIN_DIR "${OOML_TRUNK_DIR}/bin")
set(OOML_DATA_DIR "${OOML_TRUNK_DIR}/data")

set(LIBRARY_OUTPUT_PATH ${OOML_LIB_DIR})
set(EXECUTABLE_OUTPUT_PATH ${OOML_BIN_DIR})

# Include directories.
include_directories(${OOML_SRC_DIR})

# Link directories.
link_directories(${OOML_LIB_DIR})

# List of all project modules.
add_subdirectory("src")
add_subdirectory("test")
add_subdirectory("data")

# Installation paths.
if (WIN32)
	set(CMAKE_INSTALL_PREFIX "${OOML_TRUNK_DIR}")
else(WIN32)
	set(CMAKE_INSTALL_PREFIX "/usr/")
endif(WIN32)

# Build flags.
if (NOT WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb")
	set(COMPILATION_FLAGS "-W -Wall -O2 -ggdb" CACHE STRING "CMake compilation flags")
endif(NOT WIN32)

# Build type.
set(CMAKE_BUILD_TYPE "Debug")

#Create Config File
configure_file( ${OOML_SRC_DIR}/config.h.in ${OOML_SRC_DIR}/config.h )
