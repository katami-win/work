# -*- CMakeLists.txt -*-
#------------------------------------------------------------
# @file   CMakeLists.txt
# @brief  CMakeLists.txt for Accelerometer unit test
# @date   $Date: $
# @author 
#
# $Id: CMakeLists.txt 182 2014-06-17 01:14:05Z pi $
#
#------------------------------------------------------------
#
# $Log: $
#
#

PROJECT(Accelerometer)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)
find_package (Threads)
ADD_EXECUTABLE(AccelerometerTests "${PROJECT_SOURCE_DIR}/AccelerometerTests.cpp" "${PROJECT_SOURCE_DIR}/../../Accelerometer.cpp" "${PROJECT_SOURCE_DIR}/../../Task.cpp" "${PROJECT_SOURCE_DIR}/../../Split.cpp")
target_link_libraries(AccelerometerTests pthread)
include_directories("${PROJECT_SOURCE_DIR}/../../")

