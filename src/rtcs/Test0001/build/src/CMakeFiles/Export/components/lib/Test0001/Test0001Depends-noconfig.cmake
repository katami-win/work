#----------------------------------------------------------------
# Generated CMake target import file for configuration "".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Test0001" for configuration ""
set_property(TARGET Test0001 APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(Test0001 PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "pthread;omniORB4;omnithread;omniDynamic4;RTC;coil"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/lib/Test0001.so"
  IMPORTED_SONAME_NOCONFIG "Test0001.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS Test0001 )
list(APPEND _IMPORT_CHECK_FILES_FOR_Test0001 "${_IMPORT_PREFIX}/components/lib/Test0001.so" )

# Import target "Test0001Comp" for configuration ""
set_property(TARGET Test0001Comp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(Test0001Comp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/components/bin/Test0001Comp"
  )

list(APPEND _IMPORT_CHECK_TARGETS Test0001Comp )
list(APPEND _IMPORT_CHECK_FILES_FOR_Test0001Comp "${_IMPORT_PREFIX}/components/bin/Test0001Comp" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
