# AccelerometerRTC CMake config file
#
# This file sets the following variables:
# AccelerometerRTC_FOUND - Always TRUE.
# AccelerometerRTC_INCLUDE_DIRS - Directories containing the AccelerometerRTC include files.
# AccelerometerRTC_IDL_DIRS - Directories containing the AccelerometerRTC IDL files.
# AccelerometerRTC_LIBRARIES - Libraries needed to use AccelerometerRTC.
# AccelerometerRTC_DEFINITIONS - Compiler flags for AccelerometerRTC.
# AccelerometerRTC_VERSION - The version of AccelerometerRTC found.
# AccelerometerRTC_VERSION_MAJOR - The major version of AccelerometerRTC found.
# AccelerometerRTC_VERSION_MINOR - The minor version of AccelerometerRTC found.
# AccelerometerRTC_VERSION_REVISION - The revision version of AccelerometerRTC found.
# AccelerometerRTC_VERSION_CANDIDATE - The candidate version of AccelerometerRTC found.

message(STATUS "Found AccelerometerRTC-1.0.0")
set(AccelerometerRTC_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(AccelerometerRTC_INCLUDE_DIRS
#    "/usr/local/include/accelerometerrtc-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(AccelerometerRTC_IDL_DIRS
#    "/usr/local/include/accelerometerrtc-1/idl")
set(AccelerometerRTC_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(AccelerometerRTC_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(AccelerometerRTC_LIBRARIES
        "/usr/local/components/lib/libaccelerometerrtc.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(AccelerometerRTC_LIBRARIES
        "/usr/local/components/lib/libaccelerometerrtc.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(AccelerometerRTC_DEFINITIONS ${<dependency>_DEFINITIONS})

set(AccelerometerRTC_VERSION 1.0.0)
set(AccelerometerRTC_VERSION_MAJOR 1)
set(AccelerometerRTC_VERSION_MINOR 0)
set(AccelerometerRTC_VERSION_REVISION 0)
set(AccelerometerRTC_VERSION_CANDIDATE )

