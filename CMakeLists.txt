cmake_minimum_required(VERSION 2.8)

project(Calendar2)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11 -Wall -Werror -Wextra")

FILE(GLOB_RECURSE sources_files "src/*.cpp")
FILE(GLOB_RECURSE headers_files "inc/*.h")
message(STATUS "My sources:  ${sources_files}")
message(STATUS "My headers:  ${headers_files}")
#SET(project_files ${headers_files} ${sources_files})

#for qt
#add_custom_target(Calendar2 SOURCES ${project_files})
INCLUDE_DIRECTORIES("inc")
add_executable(Calendar2 ${sources_files})
