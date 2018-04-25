# IlluminationRTC CMake config file
#
# This file sets the following variables:
# IlluminationRTC_FOUND - Always TRUE.
# IlluminationRTC_INCLUDE_DIRS - Directories containing the IlluminationRTC include files.
# IlluminationRTC_IDL_DIRS - Directories containing the IlluminationRTC IDL files.
# IlluminationRTC_LIBRARIES - Libraries needed to use IlluminationRTC.
# IlluminationRTC_DEFINITIONS - Compiler flags for IlluminationRTC.
# IlluminationRTC_VERSION - The version of IlluminationRTC found.
# IlluminationRTC_VERSION_MAJOR - The major version of IlluminationRTC found.
# IlluminationRTC_VERSION_MINOR - The minor version of IlluminationRTC found.
# IlluminationRTC_VERSION_REVISION - The revision version of IlluminationRTC found.
# IlluminationRTC_VERSION_CANDIDATE - The candidate version of IlluminationRTC found.

message(STATUS "Found IlluminationRTC-1.0.0")
set(IlluminationRTC_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(IlluminationRTC_INCLUDE_DIRS
#    "/usr/local/include/illuminationrtc-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(IlluminationRTC_IDL_DIRS
#    "/usr/local/include/illuminationrtc-1/idl")
set(IlluminationRTC_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(IlluminationRTC_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(IlluminationRTC_LIBRARIES
        "/usr/local/components/lib/libilluminationrtc.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(IlluminationRTC_LIBRARIES
        "/usr/local/components/lib/libilluminationrtc.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(IlluminationRTC_DEFINITIONS ${<dependency>_DEFINITIONS})

set(IlluminationRTC_VERSION 1.0.0)
set(IlluminationRTC_VERSION_MAJOR 1)
set(IlluminationRTC_VERSION_MINOR 0)
set(IlluminationRTC_VERSION_REVISION 0)
set(IlluminationRTC_VERSION_CANDIDATE )

