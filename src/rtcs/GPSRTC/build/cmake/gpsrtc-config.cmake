# GPSRTC CMake config file
#
# This file sets the following variables:
# GPSRTC_FOUND - Always TRUE.
# GPSRTC_INCLUDE_DIRS - Directories containing the GPSRTC include files.
# GPSRTC_IDL_DIRS - Directories containing the GPSRTC IDL files.
# GPSRTC_LIBRARIES - Libraries needed to use GPSRTC.
# GPSRTC_DEFINITIONS - Compiler flags for GPSRTC.
# GPSRTC_VERSION - The version of GPSRTC found.
# GPSRTC_VERSION_MAJOR - The major version of GPSRTC found.
# GPSRTC_VERSION_MINOR - The minor version of GPSRTC found.
# GPSRTC_VERSION_REVISION - The revision version of GPSRTC found.
# GPSRTC_VERSION_CANDIDATE - The candidate version of GPSRTC found.

message(STATUS "Found GPSRTC-1.0.0")
set(GPSRTC_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(GPSRTC_INCLUDE_DIRS
#    "/usr/local/include/gpsrtc-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(GPSRTC_IDL_DIRS
#    "/usr/local/include/gpsrtc-1/idl")
set(GPSRTC_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(GPSRTC_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(GPSRTC_LIBRARIES
        "/usr/local/components/lib/libgpsrtc.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(GPSRTC_LIBRARIES
        "/usr/local/components/lib/libgpsrtc.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(GPSRTC_DEFINITIONS ${<dependency>_DEFINITIONS})

set(GPSRTC_VERSION 1.0.0)
set(GPSRTC_VERSION_MAJOR 1)
set(GPSRTC_VERSION_MINOR 0)
set(GPSRTC_VERSION_REVISION 0)
set(GPSRTC_VERSION_CANDIDATE )

