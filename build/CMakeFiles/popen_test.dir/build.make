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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/s36peng/cpp2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/s36peng/cpp2/build

# Include any dependencies generated for this target.
include CMakeFiles/popen_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/popen_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/popen_test.dir/flags.make

CMakeFiles/popen_test.dir/popen_test.cpp.o: CMakeFiles/popen_test.dir/flags.make
CMakeFiles/popen_test.dir/popen_test.cpp.o: ../popen_test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/s36peng/cpp2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/popen_test.dir/popen_test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/popen_test.dir/popen_test.cpp.o -c /home/s36peng/cpp2/popen_test.cpp

CMakeFiles/popen_test.dir/popen_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/popen_test.dir/popen_test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/s36peng/cpp2/popen_test.cpp > CMakeFiles/popen_test.dir/popen_test.cpp.i

CMakeFiles/popen_test.dir/popen_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/popen_test.dir/popen_test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/s36peng/cpp2/popen_test.cpp -o CMakeFiles/popen_test.dir/popen_test.cpp.s

CMakeFiles/popen_test.dir/popen_test.cpp.o.requires:
.PHONY : CMakeFiles/popen_test.dir/popen_test.cpp.o.requires

CMakeFiles/popen_test.dir/popen_test.cpp.o.provides: CMakeFiles/popen_test.dir/popen_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/popen_test.dir/build.make CMakeFiles/popen_test.dir/popen_test.cpp.o.provides.build
.PHONY : CMakeFiles/popen_test.dir/popen_test.cpp.o.provides

CMakeFiles/popen_test.dir/popen_test.cpp.o.provides.build: CMakeFiles/popen_test.dir/popen_test.cpp.o

# Object files for target popen_test
popen_test_OBJECTS = \
"CMakeFiles/popen_test.dir/popen_test.cpp.o"

# External object files for target popen_test
popen_test_EXTERNAL_OBJECTS =

popen_test: CMakeFiles/popen_test.dir/popen_test.cpp.o
popen_test: CMakeFiles/popen_test.dir/build.make
popen_test: CMakeFiles/popen_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable popen_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/popen_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/popen_test.dir/build: popen_test
.PHONY : CMakeFiles/popen_test.dir/build

CMakeFiles/popen_test.dir/requires: CMakeFiles/popen_test.dir/popen_test.cpp.o.requires
.PHONY : CMakeFiles/popen_test.dir/requires

CMakeFiles/popen_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/popen_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/popen_test.dir/clean

CMakeFiles/popen_test.dir/depend:
	cd /home/s36peng/cpp2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/s36peng/cpp2 /home/s36peng/cpp2 /home/s36peng/cpp2/build /home/s36peng/cpp2/build /home/s36peng/cpp2/build/CMakeFiles/popen_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/popen_test.dir/depend

