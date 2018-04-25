# BarometerRTC CMake config file
#
# This file sets the following variables:
# BarometerRTC_FOUND - Always TRUE.
# BarometerRTC_INCLUDE_DIRS - Directories containing the BarometerRTC include files.
# BarometerRTC_IDL_DIRS - Directories containing the BarometerRTC IDL files.
# BarometerRTC_LIBRARIES - Libraries needed to use BarometerRTC.
# BarometerRTC_DEFINITIONS - Compiler flags for BarometerRTC.
# BarometerRTC_VERSION - The version of BarometerRTC found.
# BarometerRTC_VERSION_MAJOR - The major version of BarometerRTC found.
# BarometerRTC_VERSION_MINOR - The minor version of BarometerRTC found.
# BarometerRTC_VERSION_REVISION - The revision version of BarometerRTC found.
# BarometerRTC_VERSION_CANDIDATE - The candidate version of BarometerRTC found.

message(STATUS "Found BarometerRTC-1.0.0")
set(BarometerRTC_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(BarometerRTC_INCLUDE_DIRS
#    "/usr/local/include/barometerrtc-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(BarometerRTC_IDL_DIRS
#    "/usr/local/include/barometerrtc-1/idl")
set(BarometerRTC_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(BarometerRTC_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(BarometerRTC_LIBRARIES
        "/usr/local/components/lib/libbarometerrtc.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(BarometerRTC_LIBRARIES
        "/usr/local/components/lib/libbarometerrtc.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(BarometerRTC_DEFINITIONS ${<dependency>_DEFINITIONS})

set(BarometerRTC_VERSION 1.0.0)
set(BarometerRTC_VERSION_MAJOR 1)
set(BarometerRTC_VERSION_MINOR 0)
set(BarometerRTC_VERSION_REVISION 0)
set(BarometerRTC_VERSION_CANDIDATE )

