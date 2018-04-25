#----------------------------------------------------------------
# Generated CMake target import file for configuration "".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "IlluminationRTC" for configuration ""
set_property(TARGET IlluminationRTC APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(IlluminationRTC PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "pthread;omniORB4;omnithread;omniDynamic4;RTC;coil"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/lib/IlluminationRTC.so"
  IMPORTED_SONAME_NOCONFIG "IlluminationRTC.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS IlluminationRTC )
list(APPEND _IMPORT_CHECK_FILES_FOR_IlluminationRTC "${_IMPORT_PREFIX}/components/lib/IlluminationRTC.so" )

# Import target "IlluminationRTCComp" for configuration ""
set_property(TARGET IlluminationRTCComp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(IlluminationRTCComp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/bin/IlluminationRTCComp"
  )

list(APPEND _IMPORT_CHECK_TARGETS IlluminationRTCComp )
list(APPEND _IMPORT_CHECK_FILES_FOR_IlluminationRTCComp "${_IMPORT_PREFIX}/components/bin/IlluminationRTCComp" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
