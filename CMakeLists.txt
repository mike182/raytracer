cmake_minimum_required(VERSION 3.1)

project(raytracer)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")
set(CMAKE_CXX_COMPILER clang++)
list(APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -W -Wall -Werror -Wextra -pedantic -g3")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PNG REQUIRED)

set (SOURCES
  main.cpp
  # World
  World/World.cpp
  World/ViewPlane.cpp
  Ray.cpp
  Tracer.cpp
  # Objects
  GeometricObjects/GeometricObject.cpp
  GeometricObjects/SingleSphere.cpp
  GeometricObjects/Plane.cpp
  GeometricObjects/Sphere.cpp
  # Utilities
  Utilities/ShadeRec.cpp
  Utilities/RGBColor.cpp
  Utilities/Point2D.cpp
  Utilities/Point3D.cpp
  Utilities/Vector3D.cpp
  Utilities/Normal.cpp
  )

include_directories (
  .
  GeometricObjects/
  Utilities/
  World/
  )

set(EXECUTABLE_NAME rt)

add_executable(${EXECUTABLE_NAME} ${SOURCES})

target_link_libraries(${EXECUTABLE_NAME} ${PNG_LIBRARY})
