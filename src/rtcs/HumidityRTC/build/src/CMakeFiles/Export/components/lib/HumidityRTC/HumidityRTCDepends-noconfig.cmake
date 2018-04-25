#----------------------------------------------------------------
# Generated CMake target import file for configuration "".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "HumidityRTC" for configuration ""
set_property(TARGET HumidityRTC APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(HumidityRTC PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "pthread;omniORB4;omnithread;omniDynamic4;RTC;coil"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/lib/HumidityRTC.so"
  IMPORTED_SONAME_NOCONFIG "HumidityRTC.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS HumidityRTC )
list(APPEND _IMPORT_CHECK_FILES_FOR_HumidityRTC "${_IMPORT_PREFIX}/components/lib/HumidityRTC.so" )

# Import target "HumidityRTCComp" for configuration ""
set_property(TARGET HumidityRTCComp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(HumidityRTCComp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/bin/HumidityRTCComp"
  )

list(APPEND _IMPORT_CHECK_TARGETS HumidityRTCComp )
list(APPEND _IMPORT_CHECK_FILES_FOR_HumidityRTCComp "${_IMPORT_PREFIX}/components/bin/HumidityRTCComp" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
