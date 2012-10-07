cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0011 NEW)

# Create core library
file(GLOB CORE_SOURCES "*.h" "*.cpp")
add_library(OOMLCore SHARED ${CORE_SOURCES})

# Install core library
install(TARGETS OOMLCore DESTINATION lib)
file(GLOB CORE_HEADERS "*.h")
install(FILES ${CORE_HEADERS} DESTINATION include/ooml/core)
