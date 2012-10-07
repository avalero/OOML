cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0011 NEW)

# List of all project modules.
add_subdirectory("core")
add_subdirectory("components")
add_subdirectory("parts")

file(GLOB BASE_HEADERS "*.h")
install(FILES ${BASE_HEADERS} DESTINATION include/ooml)
