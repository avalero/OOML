# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/avalero/workspace/OOML

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/avalero/workspace/OOML/build

# Include any dependencies generated for this target.
include test/CMakeFiles/attachment.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/attachment.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/attachment.dir/flags.make

test/CMakeFiles/attachment.dir/attachment.cpp.o: test/CMakeFiles/attachment.dir/flags.make
test/CMakeFiles/attachment.dir/attachment.cpp.o: ../test/attachment.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/avalero/workspace/OOML/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object test/CMakeFiles/attachment.dir/attachment.cpp.o"
	cd /home/avalero/workspace/OOML/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/attachment.dir/attachment.cpp.o -c /home/avalero/workspace/OOML/test/attachment.cpp

test/CMakeFiles/attachment.dir/attachment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/attachment.dir/attachment.cpp.i"
	cd /home/avalero/workspace/OOML/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/avalero/workspace/OOML/test/attachment.cpp > CMakeFiles/attachment.dir/attachment.cpp.i

test/CMakeFiles/attachment.dir/attachment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/attachment.dir/attachment.cpp.s"
	cd /home/avalero/workspace/OOML/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/avalero/workspace/OOML/test/attachment.cpp -o CMakeFiles/attachment.dir/attachment.cpp.s

test/CMakeFiles/attachment.dir/attachment.cpp.o.requires:
.PHONY : test/CMakeFiles/attachment.dir/attachment.cpp.o.requires

test/CMakeFiles/attachment.dir/attachment.cpp.o.provides: test/CMakeFiles/attachment.dir/attachment.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/attachment.dir/build.make test/CMakeFiles/attachment.dir/attachment.cpp.o.provides.build
.PHONY : test/CMakeFiles/attachment.dir/attachment.cpp.o.provides

test/CMakeFiles/attachment.dir/attachment.cpp.o.provides.build: test/CMakeFiles/attachment.dir/attachment.cpp.o

# Object files for target attachment
attachment_OBJECTS = \
"CMakeFiles/attachment.dir/attachment.cpp.o"

# External object files for target attachment
attachment_EXTERNAL_OBJECTS =

../bin/attachment: test/CMakeFiles/attachment.dir/attachment.cpp.o
../bin/attachment: test/CMakeFiles/attachment.dir/build.make
../bin/attachment: ../lib/libOOMLCore.so
../bin/attachment: ../lib/libOOMLComponents.so
../bin/attachment: ../lib/libOOMLParts.so
../bin/attachment: ../lib/libOOMLComponents.so
../bin/attachment: ../lib/libOOMLCore.so
../bin/attachment: test/CMakeFiles/attachment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/attachment"
	cd /home/avalero/workspace/OOML/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/attachment.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/attachment.dir/build: ../bin/attachment
.PHONY : test/CMakeFiles/attachment.dir/build

test/CMakeFiles/attachment.dir/requires: test/CMakeFiles/attachment.dir/attachment.cpp.o.requires
.PHONY : test/CMakeFiles/attachment.dir/requires

test/CMakeFiles/attachment.dir/clean:
	cd /home/avalero/workspace/OOML/build/test && $(CMAKE_COMMAND) -P CMakeFiles/attachment.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/attachment.dir/clean

test/CMakeFiles/attachment.dir/depend:
	cd /home/avalero/workspace/OOML/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/avalero/workspace/OOML /home/avalero/workspace/OOML/test /home/avalero/workspace/OOML/build /home/avalero/workspace/OOML/build/test /home/avalero/workspace/OOML/build/test/CMakeFiles/attachment.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/attachment.dir/depend
