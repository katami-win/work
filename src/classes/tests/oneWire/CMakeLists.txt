# -*- CMakeLists.txt -*-
#------------------------------------------------------------
# @file   CMakeLists.txt
# @brief  CMakeLists.txt for oneWire unit test
# @date   $Date: 2014-06-17 10:14:05 +0900 (Tue, 17 Jun 2014) $
# @author Sophia Planning Inc.
#
# $Id: CMakeLists.txt 182 2014-06-17 01:14:05Z pi $
#
#------------------------------------------------------------
#
# $Log: $
#
#

PROJECT(OneWire)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)

ADD_EXECUTABLE(OneWireTests "${PROJECT_SOURCE_DIR}/OneWireTests.cpp" "${PROJECT_SOURCE_DIR}/../../OneWire.cpp")
target_link_libraries(OneWireTests)
include_directories("${PROJECT_SOURCE_DIR}/../../")

