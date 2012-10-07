cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0011 NEW)

# Include runtest function library
include(runtest)

# Add test executables
add_executable(writer writer.cpp)
target_link_libraries(writer OOMLCore)
#install(TARGETS writer DESTINATION bin)

# Add test executables
add_executable(clamps clamps.cpp)
target_link_libraries(clamps OOMLCore OOMLComponents)
#install(TARGETS clamps DESTINATION bin)

# Add test executables
add_executable(sharedptr sharedptr.cpp)
target_link_libraries(sharedptr)
#install(TARGETS sharedptr DESTINATION bin)

# Add test executables
add_executable(cube cube.cpp)
target_link_libraries(cube OOMLCore OOMLComponents OOMLParts)
#install(TARGETS cube DESTINATION bin)

# Add test executables
add_executable(prism prism.cpp)
target_link_libraries(prism OOMLCore OOMLComponents)
#install(TARGETS prism DESTINATION bin)

# Add test executables
add_executable(regular regular.cpp)
target_link_libraries(regular OOMLCore OOMLComponents)
#install(TARGETS regular DESTINATION bin)

# Add test executables
add_executable(subsystem2D subsystem2D.cpp)
target_link_libraries(subsystem2D OOMLCore OOMLComponents)
#install(TARGETS subsystem2D DESTINATION bin)

# Add test executables
add_executable(toroid toroid.cpp)
target_link_libraries(toroid OOMLCore OOMLComponents)
#install(TARGETS toroid DESTINATION bin)

# Add test executables
add_executable(rounded rounded.cpp)
target_link_libraries(rounded OOMLCore OOMLComponents)
#install(TARGETS rounded DESTINATION bin)

# Add simple tests for all the targets
simple_test(writer)
simple_test(clamps)
simple_test(sharedptr)
simple_test(cube)
simple_test(prism)
simple_test(regular)
simple_test(subsystem2D)
simple_test(toroid)
simple_test(rounded)
simple_test(miniSkybot)
