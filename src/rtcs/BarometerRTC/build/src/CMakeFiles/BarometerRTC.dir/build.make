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
CMAKE_SOURCE_DIR = /home/pi/work/src/rtcs/BarometerRTC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/work/src/rtcs/BarometerRTC/build

# Include any dependencies generated for this target.
include src/CMakeFiles/BarometerRTC.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/BarometerRTC.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/BarometerRTC.dir/flags.make

src/CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.o: src/CMakeFiles/BarometerRTC.dir/flags.make
src/CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.o: ../src/BarometerRTC.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/work/src/rtcs/BarometerRTC/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.o"
	cd /home/pi/work/src/rtcs/BarometerRTC/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.o -c /home/pi/work/src/rtcs/BarometerRTC/src/BarometerRTC.cpp

src/CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.i"
	cd /home/pi/work/src/rtcs/BarometerRTC/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/work/src/rtcs/BarometerRTC/src/BarometerRTC.cpp > CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.i

src/CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.s"
	cd /home/pi/work/src/rtcs/BarometerRTC/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/work/src/rtcs/BarometerRTC/src/BarometerRTC.cpp -o CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.s

src/CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.o.requires:
.PHONY : src/CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.o.requires

src/CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.o.provides: src/CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/BarometerRTC.dir/build.make src/CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.o.provides.build
.PHONY : src/CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.o.provides

src/CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.o.provides.build: src/CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.o

src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.o: src/CMakeFiles/BarometerRTC.dir/flags.make
src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.o: /home/pi/work/src/classes/Pressure.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/work/src/rtcs/BarometerRTC/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.o"
	cd /home/pi/work/src/rtcs/BarometerRTC/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.o -c /home/pi/work/src/classes/Pressure.cpp

src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.i"
	cd /home/pi/work/src/rtcs/BarometerRTC/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/work/src/classes/Pressure.cpp > CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.i

src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.s"
	cd /home/pi/work/src/rtcs/BarometerRTC/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/work/src/classes/Pressure.cpp -o CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.s

src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.o.requires:
.PHONY : src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.o.requires

src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.o.provides: src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/BarometerRTC.dir/build.make src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.o.provides.build
.PHONY : src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.o.provides

src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.o.provides.build: src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.o

src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o: src/CMakeFiles/BarometerRTC.dir/flags.make
src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o: /home/pi/work/src/classes/GetDatetimeString.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/work/src/rtcs/BarometerRTC/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o"
	cd /home/pi/work/src/rtcs/BarometerRTC/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o -c /home/pi/work/src/classes/GetDatetimeString.cpp

src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.i"
	cd /home/pi/work/src/rtcs/BarometerRTC/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/work/src/classes/GetDatetimeString.cpp > CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.i

src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.s"
	cd /home/pi/work/src/rtcs/BarometerRTC/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/work/src/classes/GetDatetimeString.cpp -o CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.s

src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.requires:
.PHONY : src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.requires

src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.provides: src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/BarometerRTC.dir/build.make src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.provides.build
.PHONY : src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.provides

src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.provides.build: src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o

# Object files for target BarometerRTC
BarometerRTC_OBJECTS = \
"CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.o" \
"CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.o" \
"CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o"

# External object files for target BarometerRTC
BarometerRTC_EXTERNAL_OBJECTS =

src/BarometerRTC.so: src/CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.o
src/BarometerRTC.so: src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.o
src/BarometerRTC.so: src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o
src/BarometerRTC.so: src/CMakeFiles/BarometerRTC.dir/build.make
src/BarometerRTC.so: src/CMakeFiles/BarometerRTC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library BarometerRTC.so"
	cd /home/pi/work/src/rtcs/BarometerRTC/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BarometerRTC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/BarometerRTC.dir/build: src/BarometerRTC.so
.PHONY : src/CMakeFiles/BarometerRTC.dir/build

src/CMakeFiles/BarometerRTC.dir/requires: src/CMakeFiles/BarometerRTC.dir/BarometerRTC.cpp.o.requires
src/CMakeFiles/BarometerRTC.dir/requires: src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/Pressure.cpp.o.requires
src/CMakeFiles/BarometerRTC.dir/requires: src/CMakeFiles/BarometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.requires
.PHONY : src/CMakeFiles/BarometerRTC.dir/requires

src/CMakeFiles/BarometerRTC.dir/clean:
	cd /home/pi/work/src/rtcs/BarometerRTC/build/src && $(CMAKE_COMMAND) -P CMakeFiles/BarometerRTC.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/BarometerRTC.dir/clean

src/CMakeFiles/BarometerRTC.dir/depend:
	cd /home/pi/work/src/rtcs/BarometerRTC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/work/src/rtcs/BarometerRTC /home/pi/work/src/rtcs/BarometerRTC/src /home/pi/work/src/rtcs/BarometerRTC/build /home/pi/work/src/rtcs/BarometerRTC/build/src /home/pi/work/src/rtcs/BarometerRTC/build/src/CMakeFiles/BarometerRTC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/BarometerRTC.dir/depend

