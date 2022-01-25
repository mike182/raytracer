cmake_minimum_required(VERSION 3.1)

project(raytracer)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")
set(CMAKE_CXX_COMPILER clang++)
list(APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -W -Wall -Werror -Wextra -pedantic -g")

find_package(PNG REQUIRED)

set (SOURCES
  main.cpp
  World.cpp
  ViewPlane.cpp
  Ray.cpp
  ShadeRec.cpp
  GeometricObject.cpp
  Point2D.cpp
  Point3D.cpp
  Vector3D.cpp
  Normal.cpp
  RGBColor.cpp
  )

include_directories (
  .
  )

set(EXECUTABLE_NAME rt)

add_executable(${EXECUTABLE_NAME} ${SOURCES})

target_link_libraries(${EXECUTABLE_NAME} ${PNG_LIBRARY})
