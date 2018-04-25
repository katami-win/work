# Test0001 CMake config file
#
# This file sets the following variables:
# Test0001_FOUND - Always TRUE.
# Test0001_INCLUDE_DIRS - Directories containing the Test0001 include files.
# Test0001_IDL_DIRS - Directories containing the Test0001 IDL files.
# Test0001_LIBRARIES - Libraries needed to use Test0001.
# Test0001_DEFINITIONS - Compiler flags for Test0001.
# Test0001_VERSION - The version of Test0001 found.
# Test0001_VERSION_MAJOR - The major version of Test0001 found.
# Test0001_VERSION_MINOR - The minor version of Test0001 found.
# Test0001_VERSION_REVISION - The revision version of Test0001 found.
# Test0001_VERSION_CANDIDATE - The candidate version of Test0001 found.

message(STATUS "Found Test0001-1.0.0")
set(Test0001_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(Test0001_INCLUDE_DIRS
#    "/usr/local/include/test0001-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(Test0001_IDL_DIRS
#    "/usr/local/include/test0001-1/idl")
set(Test0001_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(Test0001_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(Test0001_LIBRARIES
        "/usr/local/components/lib/libtest0001.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(Test0001_LIBRARIES
        "/usr/local/components/lib/libtest0001.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(Test0001_DEFINITIONS ${<dependency>_DEFINITIONS})

set(Test0001_VERSION 1.0.0)
set(Test0001_VERSION_MAJOR 1)
set(Test0001_VERSION_MINOR 0)
set(Test0001_VERSION_REVISION 0)
set(Test0001_VERSION_CANDIDATE )

