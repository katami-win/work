#----------------------------------------------------------------
# Generated CMake target import file for configuration "".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "AccelerometerRTC" for configuration ""
set_property(TARGET AccelerometerRTC APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(AccelerometerRTC PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "pthread;omniORB4;omnithread;omniDynamic4;RTC;coil"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/lib/AccelerometerRTC.so"
  IMPORTED_SONAME_NOCONFIG "AccelerometerRTC.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS AccelerometerRTC )
list(APPEND _IMPORT_CHECK_FILES_FOR_AccelerometerRTC "${_IMPORT_PREFIX}/components/lib/AccelerometerRTC.so" )

# Import target "AccelerometerRTCComp" for configuration ""
set_property(TARGET AccelerometerRTCComp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(AccelerometerRTCComp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/bin/AccelerometerRTCComp"
  )

list(APPEND _IMPORT_CHECK_TARGETS AccelerometerRTCComp )
list(APPEND _IMPORT_CHECK_FILES_FOR_AccelerometerRTCComp "${_IMPORT_PREFIX}/components/bin/AccelerometerRTCComp" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
