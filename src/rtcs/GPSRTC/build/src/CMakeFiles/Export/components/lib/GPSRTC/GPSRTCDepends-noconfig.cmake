#----------------------------------------------------------------
# Generated CMake target import file for configuration "".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "GPSRTC" for configuration ""
set_property(TARGET GPSRTC APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(GPSRTC PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "pthread;omniORB4;omnithread;omniDynamic4;RTC;coil"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/lib/GPSRTC.so"
  IMPORTED_SONAME_NOCONFIG "GPSRTC.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS GPSRTC )
list(APPEND _IMPORT_CHECK_FILES_FOR_GPSRTC "${_IMPORT_PREFIX}/components/lib/GPSRTC.so" )

# Import target "GPSRTCComp" for configuration ""
set_property(TARGET GPSRTCComp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(GPSRTCComp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/bin/GPSRTCComp"
  )

list(APPEND _IMPORT_CHECK_TARGETS GPSRTCComp )
list(APPEND _IMPORT_CHECK_FILES_FOR_GPSRTCComp "${_IMPORT_PREFIX}/components/bin/GPSRTCComp" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
