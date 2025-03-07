# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\todoCpp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\todoCpp_autogen.dir\\ParseCache.txt"
  "todoCpp_autogen"
  )
endif()
