#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "charo::charo" for configuration "Release"
set_property(TARGET charo::charo APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(charo::charo PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libcharo.a"
  )

list(APPEND _cmake_import_check_targets charo::charo )
list(APPEND _cmake_import_check_files_for_charo::charo "${_IMPORT_PREFIX}/lib/libcharo.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
