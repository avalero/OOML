cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0011 NEW)

# Create components library
file(GLOB COMPONENTS_SOURCES "*.h" "*.cpp")
add_library(OOMLComponents SHARED ${COMPONENTS_SOURCES})
target_link_libraries(OOMLComponents OOMLCore)

# Install components library
install(TARGETS OOMLComponents DESTINATION lib)
file(GLOB COMPONENTS_HEADERS "*.h")
install(FILES ${COMPONENTS_HEADERS} DESTINATION include/ooml/components)
