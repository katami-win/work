# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/pi/work/src/rtcs/AccelerometerRTC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/work/src/rtcs/AccelerometerRTC

# Include any dependencies generated for this target.
include src/CMakeFiles/AccelerometerRTC.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/AccelerometerRTC.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/AccelerometerRTC.dir/flags.make

src/CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.o: src/CMakeFiles/AccelerometerRTC.dir/flags.make
src/CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.o: src/AccelerometerRTC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/work/src/rtcs/AccelerometerRTC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.o"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.o -c /home/pi/work/src/rtcs/AccelerometerRTC/src/AccelerometerRTC.cpp

src/CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.i"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/work/src/rtcs/AccelerometerRTC/src/AccelerometerRTC.cpp > CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.i

src/CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.s"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/work/src/rtcs/AccelerometerRTC/src/AccelerometerRTC.cpp -o CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.s

src/CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.o.requires:

.PHONY : src/CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.o.requires

src/CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.o.provides: src/CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/AccelerometerRTC.dir/build.make src/CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.o.provides.build
.PHONY : src/CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.o.provides

src/CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.o.provides.build: src/CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.o


src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.o: src/CMakeFiles/AccelerometerRTC.dir/flags.make
src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.o: /home/pi/work/src/classes/Accelerometer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/work/src/rtcs/AccelerometerRTC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.o"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.o -c /home/pi/work/src/classes/Accelerometer.cpp

src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.i"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/work/src/classes/Accelerometer.cpp > CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.i

src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.s"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/work/src/classes/Accelerometer.cpp -o CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.s

src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.o.requires:

.PHONY : src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.o.requires

src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.o.provides: src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/AccelerometerRTC.dir/build.make src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.o.provides.build
.PHONY : src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.o.provides

src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.o.provides.build: src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.o


src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o: src/CMakeFiles/AccelerometerRTC.dir/flags.make
src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o: /home/pi/work/src/classes/GetDatetimeString.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/work/src/rtcs/AccelerometerRTC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o -c /home/pi/work/src/classes/GetDatetimeString.cpp

src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.i"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/work/src/classes/GetDatetimeString.cpp > CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.i

src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.s"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/work/src/classes/GetDatetimeString.cpp -o CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.s

src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.requires:

.PHONY : src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.requires

src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.provides: src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/AccelerometerRTC.dir/build.make src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.provides.build
.PHONY : src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.provides

src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.provides.build: src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o


src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.o: src/CMakeFiles/AccelerometerRTC.dir/flags.make
src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.o: idl/BasicDataTypeSK.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/work/src/rtcs/AccelerometerRTC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.o"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.o -c /home/pi/work/src/rtcs/AccelerometerRTC/idl/BasicDataTypeSK.cc

src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.i"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/work/src/rtcs/AccelerometerRTC/idl/BasicDataTypeSK.cc > CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.i

src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.s"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/work/src/rtcs/AccelerometerRTC/idl/BasicDataTypeSK.cc -o CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.s

src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.o.requires:

.PHONY : src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.o.requires

src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.o.provides: src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.o.requires
	$(MAKE) -f src/CMakeFiles/AccelerometerRTC.dir/build.make src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.o.provides.build
.PHONY : src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.o.provides

src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.o.provides.build: src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.o


src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.o: src/CMakeFiles/AccelerometerRTC.dir/flags.make
src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.o: idl/BasicDataTypeDynSK.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/work/src/rtcs/AccelerometerRTC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.o"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.o -c /home/pi/work/src/rtcs/AccelerometerRTC/idl/BasicDataTypeDynSK.cc

src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.i"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/work/src/rtcs/AccelerometerRTC/idl/BasicDataTypeDynSK.cc > CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.i

src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.s"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/work/src/rtcs/AccelerometerRTC/idl/BasicDataTypeDynSK.cc -o CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.s

src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.o.requires:

.PHONY : src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.o.requires

src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.o.provides: src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.o.requires
	$(MAKE) -f src/CMakeFiles/AccelerometerRTC.dir/build.make src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.o.provides.build
.PHONY : src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.o.provides

src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.o.provides.build: src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.o


# Object files for target AccelerometerRTC
AccelerometerRTC_OBJECTS = \
"CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.o" \
"CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.o" \
"CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o" \
"CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.o" \
"CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.o"

# External object files for target AccelerometerRTC
AccelerometerRTC_EXTERNAL_OBJECTS =

src/AccelerometerRTC.so: src/CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.o
src/AccelerometerRTC.so: src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.o
src/AccelerometerRTC.so: src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o
src/AccelerometerRTC.so: src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.o
src/AccelerometerRTC.so: src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.o
src/AccelerometerRTC.so: src/CMakeFiles/AccelerometerRTC.dir/build.make
src/AccelerometerRTC.so: src/CMakeFiles/AccelerometerRTC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/work/src/rtcs/AccelerometerRTC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library AccelerometerRTC.so"
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AccelerometerRTC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/AccelerometerRTC.dir/build: src/AccelerometerRTC.so

.PHONY : src/CMakeFiles/AccelerometerRTC.dir/build

src/CMakeFiles/AccelerometerRTC.dir/requires: src/CMakeFiles/AccelerometerRTC.dir/AccelerometerRTC.cpp.o.requires
src/CMakeFiles/AccelerometerRTC.dir/requires: src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/Accelerometer.cpp.o.requires
src/CMakeFiles/AccelerometerRTC.dir/requires: src/CMakeFiles/AccelerometerRTC.dir/home/pi/work/src/classes/GetDatetimeString.cpp.o.requires
src/CMakeFiles/AccelerometerRTC.dir/requires: src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeSK.cc.o.requires
src/CMakeFiles/AccelerometerRTC.dir/requires: src/CMakeFiles/AccelerometerRTC.dir/__/idl/BasicDataTypeDynSK.cc.o.requires

.PHONY : src/CMakeFiles/AccelerometerRTC.dir/requires

src/CMakeFiles/AccelerometerRTC.dir/clean:
	cd /home/pi/work/src/rtcs/AccelerometerRTC/src && $(CMAKE_COMMAND) -P CMakeFiles/AccelerometerRTC.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/AccelerometerRTC.dir/clean

src/CMakeFiles/AccelerometerRTC.dir/depend:
	cd /home/pi/work/src/rtcs/AccelerometerRTC && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/work/src/rtcs/AccelerometerRTC /home/pi/work/src/rtcs/AccelerometerRTC/src /home/pi/work/src/rtcs/AccelerometerRTC /home/pi/work/src/rtcs/AccelerometerRTC/src /home/pi/work/src/rtcs/AccelerometerRTC/src/CMakeFiles/AccelerometerRTC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/AccelerometerRTC.dir/depend

