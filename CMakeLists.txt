cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0011 NEW)

# Project ID.
project(OOML CXX C)

set(OOML_TRUNK_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
# CMake Include path.
set(CMAKE_MODULE_PATH "${OOML_TRUNK_DIR}/cmake")

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

# List of all project modules.
add_subdirectory("src")
add_subdirectory("test")
add_subdirectory("data")
