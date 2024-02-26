cmake_minimum_required(VERSION 3.10)

project(spline)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # add_compile_options(-Wall -Wextra -Wpedantic -Werror)
  #add_compile_options(-O2 -march=native)
  # add_compile_options(-march=native)
  add_compile_options(-fmax-errors=5)
endif()

find_package(Matplot++ REQUIRED)

include_directories(
    ${MATPLOT_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/lib/spline/src

)

add_executable(spline src/main.cpp)

target_link_libraries(spline PRIVATE Matplot++::matplot)
