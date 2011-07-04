cmake_minimum_required (VERSION 2.6)
project (jkdl-svg-test)

include_directories (../src)
link_directories (../src)

add_executable (loader.test loader.cxx)
target_link_libraries (loader.test jkdl_svg boost_unit_test_framework)

