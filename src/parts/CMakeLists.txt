cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0011 NEW)

# Create parts library
file(GLOB PARTS_SOURCES "*.h" "*.cpp")
add_library(OOMLParts SHARED ${PARTS_SOURCES})
target_link_libraries(OOMLParts OOMLCore OOMLComponents)

# Install parts library
install(TARGETS OOMLParts DESTINATION lib)
file(GLOB PARTS_HEADERS "*.h")
install(FILES ${PARTS_HEADERS} DESTINATION include/ooml/parts)
