#----------------------------------------------------------------
# Generated CMake target import file for configuration "".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "BarometerRTC" for configuration ""
set_property(TARGET BarometerRTC APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(BarometerRTC PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "pthread;omniORB4;omnithread;omniDynamic4;RTC;coil"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/lib/BarometerRTC.so"
  IMPORTED_SONAME_NOCONFIG "BarometerRTC.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS BarometerRTC )
list(APPEND _IMPORT_CHECK_FILES_FOR_BarometerRTC "${_IMPORT_PREFIX}/components/lib/BarometerRTC.so" )

# Import target "BarometerRTCComp" for configuration ""
set_property(TARGET BarometerRTCComp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(BarometerRTCComp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/bin/BarometerRTCComp"
  )

list(APPEND _IMPORT_CHECK_TARGETS BarometerRTCComp )
list(APPEND _IMPORT_CHECK_FILES_FOR_BarometerRTCComp "${_IMPORT_PREFIX}/components/bin/BarometerRTCComp" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
