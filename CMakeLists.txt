cmake_minimum_required(VERSION 2.8)

project(Calendar)

#add support of c++ 2011 (linux and windows)
if (CMAKE_VERSION VERSION_LESS "3.1")
  if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set (CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}")
  endif ()
else ()
  set (CMAKE_CXX_STANDARD 11)
endif ()

#add output folder
set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#add some define for the compilation of sqlite
add_definitions(-DSQLITE_THREADSAFE=0 -DSQLITE_OMIT_LOAD_EXTENSION)

#check cpp rest sdk installed
find_package(cpprestsdk REQUIRED)

#get the sources
FILE(GLOB_RECURSE sources_files "src/*.c*")
FILE(GLOB_RECURSE headers_files "inc/*.h")
message(STATUS "My sources:  ${sources_files}")
message(STATUS "My headers:  ${headers_files}")

#add the includes
INCLUDE_DIRECTORIES("inc")

#create the executable output
add_executable(Calendar ${sources_files})

#add external lib if needed
target_link_libraries(Calendar PRIVATE cpprestsdk::cpprest
  boost_system-mt
  boost_thread-mt
  boost_chrono-mt
)

