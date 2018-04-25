# -*- CMakeLists.txt -*-
#------------------------------------------------------------
# @file   CMakeLists.txt
# @brief  CMakeLists.txt for Clcd unit test
# @date   $Date: 
# @author 
#
# $Id: CMakeLists.txt 183 2014-06-17 01:15:21Z pi $
#
#------------------------------------------------------------
#
# $Log: $
#
#

PROJECT(ClcdTests)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)
find_package (Threads)
ADD_EXECUTABLE(ClcdTests "${PROJECT_SOURCE_DIR}/ClcdTests.cpp" "${PROJECT_SOURCE_DIR}/../../Clcd.cpp")
target_link_libraries(ClcdTests wiringPi pthread)

include_directories("${PROJECT_SOURCE_DIR}/../../")

