# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SmoczaBrygada_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SmoczaBrygada_autogen.dir\\ParseCache.txt"
  "SmoczaBrygada_autogen"
  )
endif()
