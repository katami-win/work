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
CMAKE_SOURCE_DIR = /home/pi/work/src/rtcs/Test0001

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/work/src/rtcs/Test0001/build

# Include any dependencies generated for this target.
include src/CMakeFiles/Test0001Comp.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Test0001Comp.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Test0001Comp.dir/flags.make

src/CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.o: src/CMakeFiles/Test0001Comp.dir/flags.make
src/CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.o: ../src/Test0001Comp.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/work/src/rtcs/Test0001/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.o"
	cd /home/pi/work/src/rtcs/Test0001/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.o -c /home/pi/work/src/rtcs/Test0001/src/Test0001Comp.cpp

src/CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.i"
	cd /home/pi/work/src/rtcs/Test0001/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/work/src/rtcs/Test0001/src/Test0001Comp.cpp > CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.i

src/CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.s"
	cd /home/pi/work/src/rtcs/Test0001/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/work/src/rtcs/Test0001/src/Test0001Comp.cpp -o CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.s

src/CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.o.requires:
.PHONY : src/CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.o.requires

src/CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.o.provides: src/CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/Test0001Comp.dir/build.make src/CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.o.provides.build
.PHONY : src/CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.o.provides

src/CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.o.provides.build: src/CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.o

src/CMakeFiles/Test0001Comp.dir/Test0001.cpp.o: src/CMakeFiles/Test0001Comp.dir/flags.make
src/CMakeFiles/Test0001Comp.dir/Test0001.cpp.o: ../src/Test0001.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/work/src/rtcs/Test0001/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/Test0001Comp.dir/Test0001.cpp.o"
	cd /home/pi/work/src/rtcs/Test0001/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Test0001Comp.dir/Test0001.cpp.o -c /home/pi/work/src/rtcs/Test0001/src/Test0001.cpp

src/CMakeFiles/Test0001Comp.dir/Test0001.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test0001Comp.dir/Test0001.cpp.i"
	cd /home/pi/work/src/rtcs/Test0001/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/work/src/rtcs/Test0001/src/Test0001.cpp > CMakeFiles/Test0001Comp.dir/Test0001.cpp.i

src/CMakeFiles/Test0001Comp.dir/Test0001.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test0001Comp.dir/Test0001.cpp.s"
	cd /home/pi/work/src/rtcs/Test0001/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/work/src/rtcs/Test0001/src/Test0001.cpp -o CMakeFiles/Test0001Comp.dir/Test0001.cpp.s

src/CMakeFiles/Test0001Comp.dir/Test0001.cpp.o.requires:
.PHONY : src/CMakeFiles/Test0001Comp.dir/Test0001.cpp.o.requires

src/CMakeFiles/Test0001Comp.dir/Test0001.cpp.o.provides: src/CMakeFiles/Test0001Comp.dir/Test0001.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/Test0001Comp.dir/build.make src/CMakeFiles/Test0001Comp.dir/Test0001.cpp.o.provides.build
.PHONY : src/CMakeFiles/Test0001Comp.dir/Test0001.cpp.o.provides

src/CMakeFiles/Test0001Comp.dir/Test0001.cpp.o.provides.build: src/CMakeFiles/Test0001Comp.dir/Test0001.cpp.o

# Object files for target Test0001Comp
Test0001Comp_OBJECTS = \
"CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.o" \
"CMakeFiles/Test0001Comp.dir/Test0001.cpp.o"

# External object files for target Test0001Comp
Test0001Comp_EXTERNAL_OBJECTS =

src/Test0001Comp: src/CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.o
src/Test0001Comp: src/CMakeFiles/Test0001Comp.dir/Test0001.cpp.o
src/Test0001Comp: src/CMakeFiles/Test0001Comp.dir/build.make
src/Test0001Comp: src/CMakeFiles/Test0001Comp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Test0001Comp"
	cd /home/pi/work/src/rtcs/Test0001/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test0001Comp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Test0001Comp.dir/build: src/Test0001Comp
.PHONY : src/CMakeFiles/Test0001Comp.dir/build

src/CMakeFiles/Test0001Comp.dir/requires: src/CMakeFiles/Test0001Comp.dir/Test0001Comp.cpp.o.requires
src/CMakeFiles/Test0001Comp.dir/requires: src/CMakeFiles/Test0001Comp.dir/Test0001.cpp.o.requires
.PHONY : src/CMakeFiles/Test0001Comp.dir/requires

src/CMakeFiles/Test0001Comp.dir/clean:
	cd /home/pi/work/src/rtcs/Test0001/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Test0001Comp.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Test0001Comp.dir/clean

src/CMakeFiles/Test0001Comp.dir/depend:
	cd /home/pi/work/src/rtcs/Test0001/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/work/src/rtcs/Test0001 /home/pi/work/src/rtcs/Test0001/src /home/pi/work/src/rtcs/Test0001/build /home/pi/work/src/rtcs/Test0001/build/src /home/pi/work/src/rtcs/Test0001/build/src/CMakeFiles/Test0001Comp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Test0001Comp.dir/depend

