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
CMAKE_SOURCE_DIR = /home/pi/work/src/classes/tests/Uart

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/work/src/classes/tests/Uart/build

# Include any dependencies generated for this target.
include CMakeFiles/UartTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UartTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UartTests.dir/flags.make

CMakeFiles/UartTests.dir/UartTests.cpp.o: CMakeFiles/UartTests.dir/flags.make
CMakeFiles/UartTests.dir/UartTests.cpp.o: ../UartTests.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/work/src/classes/tests/Uart/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/UartTests.dir/UartTests.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/UartTests.dir/UartTests.cpp.o -c /home/pi/work/src/classes/tests/Uart/UartTests.cpp

CMakeFiles/UartTests.dir/UartTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UartTests.dir/UartTests.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/work/src/classes/tests/Uart/UartTests.cpp > CMakeFiles/UartTests.dir/UartTests.cpp.i

CMakeFiles/UartTests.dir/UartTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UartTests.dir/UartTests.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/work/src/classes/tests/Uart/UartTests.cpp -o CMakeFiles/UartTests.dir/UartTests.cpp.s

CMakeFiles/UartTests.dir/UartTests.cpp.o.requires:
.PHONY : CMakeFiles/UartTests.dir/UartTests.cpp.o.requires

CMakeFiles/UartTests.dir/UartTests.cpp.o.provides: CMakeFiles/UartTests.dir/UartTests.cpp.o.requires
	$(MAKE) -f CMakeFiles/UartTests.dir/build.make CMakeFiles/UartTests.dir/UartTests.cpp.o.provides.build
.PHONY : CMakeFiles/UartTests.dir/UartTests.cpp.o.provides

CMakeFiles/UartTests.dir/UartTests.cpp.o.provides.build: CMakeFiles/UartTests.dir/UartTests.cpp.o

CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.o: CMakeFiles/UartTests.dir/flags.make
CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.o: /home/pi/work/src/classes/Uart.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/work/src/classes/tests/Uart/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.o -c /home/pi/work/src/classes/Uart.cpp

CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/work/src/classes/Uart.cpp > CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.i

CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/work/src/classes/Uart.cpp -o CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.s

CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.o.requires:
.PHONY : CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.o.requires

CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.o.provides: CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.o.requires
	$(MAKE) -f CMakeFiles/UartTests.dir/build.make CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.o.provides.build
.PHONY : CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.o.provides

CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.o.provides.build: CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.o

# Object files for target UartTests
UartTests_OBJECTS = \
"CMakeFiles/UartTests.dir/UartTests.cpp.o" \
"CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.o"

# External object files for target UartTests
UartTests_EXTERNAL_OBJECTS =

UartTests: CMakeFiles/UartTests.dir/UartTests.cpp.o
UartTests: CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.o
UartTests: CMakeFiles/UartTests.dir/build.make
UartTests: CMakeFiles/UartTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable UartTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UartTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UartTests.dir/build: UartTests
.PHONY : CMakeFiles/UartTests.dir/build

CMakeFiles/UartTests.dir/requires: CMakeFiles/UartTests.dir/UartTests.cpp.o.requires
CMakeFiles/UartTests.dir/requires: CMakeFiles/UartTests.dir/home/pi/work/src/classes/Uart.cpp.o.requires
.PHONY : CMakeFiles/UartTests.dir/requires

CMakeFiles/UartTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UartTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UartTests.dir/clean

CMakeFiles/UartTests.dir/depend:
	cd /home/pi/work/src/classes/tests/Uart/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/work/src/classes/tests/Uart /home/pi/work/src/classes/tests/Uart /home/pi/work/src/classes/tests/Uart/build /home/pi/work/src/classes/tests/Uart/build /home/pi/work/src/classes/tests/Uart/build/CMakeFiles/UartTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UartTests.dir/depend

