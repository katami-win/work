# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_SOURCE_DIR = /home/pi/work/src/classes/tests/Clcd

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/work/src/classes/tests/Clcd/build

# Include any dependencies generated for this target.
include CMakeFiles/ClcdTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ClcdTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ClcdTests.dir/flags.make

CMakeFiles/ClcdTests.dir/ClcdTests.cpp.o: CMakeFiles/ClcdTests.dir/flags.make
CMakeFiles/ClcdTests.dir/ClcdTests.cpp.o: ../ClcdTests.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/work/src/classes/tests/Clcd/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ClcdTests.dir/ClcdTests.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ClcdTests.dir/ClcdTests.cpp.o -c /home/pi/work/src/classes/tests/Clcd/ClcdTests.cpp

CMakeFiles/ClcdTests.dir/ClcdTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClcdTests.dir/ClcdTests.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/work/src/classes/tests/Clcd/ClcdTests.cpp > CMakeFiles/ClcdTests.dir/ClcdTests.cpp.i

CMakeFiles/ClcdTests.dir/ClcdTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClcdTests.dir/ClcdTests.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/work/src/classes/tests/Clcd/ClcdTests.cpp -o CMakeFiles/ClcdTests.dir/ClcdTests.cpp.s

CMakeFiles/ClcdTests.dir/ClcdTests.cpp.o.requires:
.PHONY : CMakeFiles/ClcdTests.dir/ClcdTests.cpp.o.requires

CMakeFiles/ClcdTests.dir/ClcdTests.cpp.o.provides: CMakeFiles/ClcdTests.dir/ClcdTests.cpp.o.requires
	$(MAKE) -f CMakeFiles/ClcdTests.dir/build.make CMakeFiles/ClcdTests.dir/ClcdTests.cpp.o.provides.build
.PHONY : CMakeFiles/ClcdTests.dir/ClcdTests.cpp.o.provides

CMakeFiles/ClcdTests.dir/ClcdTests.cpp.o.provides.build: CMakeFiles/ClcdTests.dir/ClcdTests.cpp.o

CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.o: CMakeFiles/ClcdTests.dir/flags.make
CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.o: /home/pi/work/src/classes/Clcd.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/work/src/classes/tests/Clcd/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.o -c /home/pi/work/src/classes/Clcd.cpp

CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/work/src/classes/Clcd.cpp > CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.i

CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/work/src/classes/Clcd.cpp -o CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.s

CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.o.requires:
.PHONY : CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.o.requires

CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.o.provides: CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.o.requires
	$(MAKE) -f CMakeFiles/ClcdTests.dir/build.make CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.o.provides.build
.PHONY : CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.o.provides

CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.o.provides.build: CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.o

# Object files for target ClcdTests
ClcdTests_OBJECTS = \
"CMakeFiles/ClcdTests.dir/ClcdTests.cpp.o" \
"CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.o"

# External object files for target ClcdTests
ClcdTests_EXTERNAL_OBJECTS =

ClcdTests: CMakeFiles/ClcdTests.dir/ClcdTests.cpp.o
ClcdTests: CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.o
ClcdTests: CMakeFiles/ClcdTests.dir/build.make
ClcdTests: CMakeFiles/ClcdTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ClcdTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ClcdTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ClcdTests.dir/build: ClcdTests
.PHONY : CMakeFiles/ClcdTests.dir/build

CMakeFiles/ClcdTests.dir/requires: CMakeFiles/ClcdTests.dir/ClcdTests.cpp.o.requires
CMakeFiles/ClcdTests.dir/requires: CMakeFiles/ClcdTests.dir/home/pi/work/src/classes/Clcd.cpp.o.requires
.PHONY : CMakeFiles/ClcdTests.dir/requires

CMakeFiles/ClcdTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ClcdTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ClcdTests.dir/clean

CMakeFiles/ClcdTests.dir/depend:
	cd /home/pi/work/src/classes/tests/Clcd/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/work/src/classes/tests/Clcd /home/pi/work/src/classes/tests/Clcd /home/pi/work/src/classes/tests/Clcd/build /home/pi/work/src/classes/tests/Clcd/build /home/pi/work/src/classes/tests/Clcd/build/CMakeFiles/ClcdTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ClcdTests.dir/depend
