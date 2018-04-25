# -*- CMakeLists.txt -*-
#------------------------------------------------------------
# @file   CMakeLists.txt
# @brief  CMakeLists.txt for Illumination unit test
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

PROJECT(Illumination)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)
find_package (Threads)
ADD_EXECUTABLE(IlluminationTests "${PROJECT_SOURCE_DIR}/IlluminationTests.cpp" "${PROJECT_SOURCE_DIR}/../../Illumination.cpp" "${PROJECT_SOURCE_DIR}/../../Task.cpp")
target_link_libraries(IlluminationTests pthread)
include_directories("${PROJECT_SOURCE_DIR}/../../")

