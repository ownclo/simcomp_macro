cmake_minimum_required(VERSION 2.6)
project(sim_comp_macro)

# For linux use only.
add_definitions(-Wall -Wextra -g -std=c++0x)

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/src)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)

include_directories(${COMMON_INCLUDES})

add_executable(../bin/macro ${sources})
