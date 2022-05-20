#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "4-sem-11-lab::4-sem-11-lab" for configuration "Debug"
set_property(TARGET 4-sem-11-lab::4-sem-11-lab APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(4-sem-11-lab::4-sem-11-lab PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/lib4-sem-11-labd.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS 4-sem-11-lab::4-sem-11-lab )
list(APPEND _IMPORT_CHECK_FILES_FOR_4-sem-11-lab::4-sem-11-lab "${_IMPORT_PREFIX}/lib/lib4-sem-11-labd.a" )

# Import target "4-sem-11-lab::builder_11_lab" for configuration "Debug"
set_property(TARGET 4-sem-11-lab::builder_11_lab APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(4-sem-11-lab::builder_11_lab PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/builder_11_lab"
  )

list(APPEND _IMPORT_CHECK_TARGETS 4-sem-11-lab::builder_11_lab )
list(APPEND _IMPORT_CHECK_FILES_FOR_4-sem-11-lab::builder_11_lab "${_IMPORT_PREFIX}/bin/builder_11_lab" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
