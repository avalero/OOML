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

# Add test executables
add_executable(refsys refsys.cpp)
target_link_libraries(refsys OOMLCore OOMLComponents)

# Add test executables
add_executable(transform transform.cpp)
target_link_libraries(transform OOMLCore OOMLComponents OOMLParts)

# Add test executables
add_executable(attachment attachment.cpp)
target_link_libraries(attachment OOMLCore OOMLComponents OOMLParts)

# Add test executables
add_executable(sandbox sandbox.cpp)
target_link_libraries(sandbox OOMLCore OOMLComponents OOMLParts)


#install(TARGETS rounded DESTINATION bin)
