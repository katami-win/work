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
CMAKE_SOURCE_DIR = /home/pi/work/src/rtcs/GPSRTC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/work/src/rtcs/GPSRTC/build

# Utility rule file for ALL_IDL_TGT.

# Include the progress variables for this target.
include idl/CMakeFiles/ALL_IDL_TGT.dir/progress.make

idl/CMakeFiles/ALL_IDL_TGT:

ALL_IDL_TGT: idl/CMakeFiles/ALL_IDL_TGT
ALL_IDL_TGT: idl/CMakeFiles/ALL_IDL_TGT.dir/build.make
.PHONY : ALL_IDL_TGT

# Rule to build all files generated by this target.
idl/CMakeFiles/ALL_IDL_TGT.dir/build: ALL_IDL_TGT
.PHONY : idl/CMakeFiles/ALL_IDL_TGT.dir/build

idl/CMakeFiles/ALL_IDL_TGT.dir/clean:
	cd /home/pi/work/src/rtcs/GPSRTC/build/idl && $(CMAKE_COMMAND) -P CMakeFiles/ALL_IDL_TGT.dir/cmake_clean.cmake
.PHONY : idl/CMakeFiles/ALL_IDL_TGT.dir/clean

idl/CMakeFiles/ALL_IDL_TGT.dir/depend:
	cd /home/pi/work/src/rtcs/GPSRTC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/work/src/rtcs/GPSRTC /home/pi/work/src/rtcs/GPSRTC/idl /home/pi/work/src/rtcs/GPSRTC/build /home/pi/work/src/rtcs/GPSRTC/build/idl /home/pi/work/src/rtcs/GPSRTC/build/idl/CMakeFiles/ALL_IDL_TGT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : idl/CMakeFiles/ALL_IDL_TGT.dir/depend

