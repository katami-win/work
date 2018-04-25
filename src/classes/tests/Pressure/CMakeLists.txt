# -*- CMakeLists.txt -*-
#------------------------------------------------------------
# @file   CMakeLists.txt
# @brief  CMakeLists.txt for Pressure unit test
# @date   $Date: 2014-06-17 10:14:05 +0900 (Tue, 17 Jun 2014) $
# @author 
#
# $Id: CMakeLists.txt 182 2014-06-17 01:14:05Z pi $
#
#------------------------------------------------------------
#
# $Log: $
#
#

PROJECT(Pressure)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)

ADD_EXECUTABLE(PressureTests "${PROJECT_SOURCE_DIR}/PressureTests.cpp" "${PROJECT_SOURCE_DIR}/../../Pressure.cpp")
target_link_libraries(PressureTests)
include_directories("${PROJECT_SOURCE_DIR}/../../")

