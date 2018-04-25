#----------------------------------------------------------------
# Generated CMake target import file for configuration "".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "TemperatureRTC" for configuration ""
set_property(TARGET TemperatureRTC APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(TemperatureRTC PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "pthread;omniORB4;omnithread;omniDynamic4;RTC;coil"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/lib/TemperatureRTC.so"
  IMPORTED_SONAME_NOCONFIG "TemperatureRTC.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS TemperatureRTC )
list(APPEND _IMPORT_CHECK_FILES_FOR_TemperatureRTC "${_IMPORT_PREFIX}/components/lib/TemperatureRTC.so" )

# Import target "TemperatureRTCComp" for configuration ""
set_property(TARGET TemperatureRTCComp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(TemperatureRTCComp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/bin/TemperatureRTCComp"
  )

list(APPEND _IMPORT_CHECK_TARGETS TemperatureRTCComp )
list(APPEND _IMPORT_CHECK_FILES_FOR_TemperatureRTCComp "${_IMPORT_PREFIX}/components/bin/TemperatureRTCComp" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
