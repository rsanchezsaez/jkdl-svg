cmake_minimum_required (VERSION 2.6)
project (jkdl-svg)

set (SOURCES edge.cxx loader.cxx network.cxx unimplemented.cxx vertex.cxx)
set (HEADERS edge.h loader.h network.h unimplemented.h vertex.h)

include_directories(${FIP_INCLUDE_PATH} ${FREEIMAGE_INCLUDE_PATH})

add_library(jkdl_svg ${SOURCES})
target_link_libraries(jkdl_svg ${FIP_LIBRARY})

