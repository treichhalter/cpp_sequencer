cmake_minimum_required(VERSION 3.18)

project ("cpp_sequencer")

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE headers_h CONFIGURE_DEPENDS "*.h")
file(GLOB_RECURSE headers_hpp CONFIGURE_DEPENDS "*.hpp")
file(GLOB_RECURSE sources LIST_DIRECTORIES false CONFIGURE_DEPENDS "*.cpp")
list(FILTER sources EXCLUDE REGEX "CMakeFiles/.*")

add_executable (main.out ${sources} ${headers_h} ${headers_hpp})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET main.out PROPERTY CXX_STANDARD 17)
endif()
