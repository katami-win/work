# HumidityRTC CMake config file
#
# This file sets the following variables:
# HumidityRTC_FOUND - Always TRUE.
# HumidityRTC_INCLUDE_DIRS - Directories containing the HumidityRTC include files.
# HumidityRTC_IDL_DIRS - Directories containing the HumidityRTC IDL files.
# HumidityRTC_LIBRARIES - Libraries needed to use HumidityRTC.
# HumidityRTC_DEFINITIONS - Compiler flags for HumidityRTC.
# HumidityRTC_VERSION - The version of HumidityRTC found.
# HumidityRTC_VERSION_MAJOR - The major version of HumidityRTC found.
# HumidityRTC_VERSION_MINOR - The minor version of HumidityRTC found.
# HumidityRTC_VERSION_REVISION - The revision version of HumidityRTC found.
# HumidityRTC_VERSION_CANDIDATE - The candidate version of HumidityRTC found.

message(STATUS "Found HumidityRTC-1.0.0")
set(HumidityRTC_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(HumidityRTC_INCLUDE_DIRS
#    "/usr/local/include/humidityrtc-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(HumidityRTC_IDL_DIRS
#    "/usr/local/include/humidityrtc-1/idl")
set(HumidityRTC_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(HumidityRTC_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(HumidityRTC_LIBRARIES
        "/usr/local/components/lib/libhumidityrtc.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(HumidityRTC_LIBRARIES
        "/usr/local/components/lib/libhumidityrtc.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(HumidityRTC_DEFINITIONS ${<dependency>_DEFINITIONS})

set(HumidityRTC_VERSION 1.0.0)
set(HumidityRTC_VERSION_MAJOR 1)
set(HumidityRTC_VERSION_MINOR 0)
set(HumidityRTC_VERSION_REVISION 0)
set(HumidityRTC_VERSION_CANDIDATE )

