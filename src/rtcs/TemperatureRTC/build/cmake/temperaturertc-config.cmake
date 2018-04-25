# TemperatureRTC CMake config file
#
# This file sets the following variables:
# TemperatureRTC_FOUND - Always TRUE.
# TemperatureRTC_INCLUDE_DIRS - Directories containing the TemperatureRTC include files.
# TemperatureRTC_IDL_DIRS - Directories containing the TemperatureRTC IDL files.
# TemperatureRTC_LIBRARIES - Libraries needed to use TemperatureRTC.
# TemperatureRTC_DEFINITIONS - Compiler flags for TemperatureRTC.
# TemperatureRTC_VERSION - The version of TemperatureRTC found.
# TemperatureRTC_VERSION_MAJOR - The major version of TemperatureRTC found.
# TemperatureRTC_VERSION_MINOR - The minor version of TemperatureRTC found.
# TemperatureRTC_VERSION_REVISION - The revision version of TemperatureRTC found.
# TemperatureRTC_VERSION_CANDIDATE - The candidate version of TemperatureRTC found.

message(STATUS "Found TemperatureRTC-1.0.0")
set(TemperatureRTC_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(TemperatureRTC_INCLUDE_DIRS
#    "/usr/local/include/temperaturertc-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(TemperatureRTC_IDL_DIRS
#    "/usr/local/include/temperaturertc-1/idl")
set(TemperatureRTC_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(TemperatureRTC_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(TemperatureRTC_LIBRARIES
        "/usr/local/components/lib/libtemperaturertc.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(TemperatureRTC_LIBRARIES
        "/usr/local/components/lib/libtemperaturertc.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(TemperatureRTC_DEFINITIONS ${<dependency>_DEFINITIONS})

set(TemperatureRTC_VERSION 1.0.0)
set(TemperatureRTC_VERSION_MAJOR 1)
set(TemperatureRTC_VERSION_MINOR 0)
set(TemperatureRTC_VERSION_REVISION 0)
set(TemperatureRTC_VERSION_CANDIDATE )

