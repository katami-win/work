# -*- CMakeLists.txt -*-
#------------------------------------------------------------
# @file   CMakeLists.txt
# @brief  CMakeLists.txt for HumidityTemperaturer unit test
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

PROJECT(HumidityTemperature)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)
find_package (Threads)
ADD_EXECUTABLE(HumidityTemperatureTests "${PROJECT_SOURCE_DIR}/HumidityTemperatureTests.cpp" "${PROJECT_SOURCE_DIR}/../../HumidityTemperature.cpp" "${PROJECT_SOURCE_DIR}/../../Task.cpp")
target_link_libraries(HumidityTemperatureTests pthread)
include_directories("${PROJECT_SOURCE_DIR}/../../")

