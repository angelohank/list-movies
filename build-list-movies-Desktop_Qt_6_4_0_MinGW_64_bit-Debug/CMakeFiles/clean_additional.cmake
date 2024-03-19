# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\list-movies_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\list-movies_autogen.dir\\ParseCache.txt"
  "list-movies_autogen"
  )
endif()
