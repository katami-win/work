# -*- CMakeLists.txt -*-
#------------------------------------------------------------
# @file   CMakeLists.txt
# @brief  CMakeLists.txt for Uart unit test
# @date   $Date: 2014-06-17 10:15:21 +0900 (²Ð, 17  6·î 2014) $
#
# $Id: CMakeLists.txt 183 2014-06-17 01:15:21Z pi $
#
#------------------------------------------------------------
#
# $Log: $
#
#

PROJECT(UartTests)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)
#ADD_EXECUTABLE(UartTests "${PROJECT_SOURCE_DIR}/UartTests.cpp" "${PROJECT_SOURCE_DIR}/../../Uart.cpp"  "${PROJECT_SOURCE_DIR}/../../Split.cpp")
ADD_EXECUTABLE(UartTests "${PROJECT_SOURCE_DIR}/UartTests.cpp" "${PROJECT_SOURCE_DIR}/../../Uart.cpp")
target_link_libraries(UartTests wiringPi)

include_directories("${PROJECT_SOURCE_DIR}/../../")

