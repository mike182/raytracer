cmake_minimum_required(VERSION 3.1)

project(raytracer)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")
set(CMAKE_CXX_COMPILER clang++)
list(APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -W -Wall -Werror -Wextra -pedantic -g3")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PNG REQUIRED)
find_package(JPEG REQUIRED)

set (SOURCES
  main.cpp
  # World
  World/World.cpp
  World/ViewPlane.cpp
  # Camera.cpp
  Ray.cpp
  # RayCast.cpp
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
  Utilities/Image.cpp
  )

include_directories (
  .
  # BRDFs/
  # Camera/
  GeometricObjects/
  # Lights/
  # Materials/
  # Samplers/
  # Tracer/
  Utilities/
  World/
  )

set(EXECUTABLE_NAME rt)

add_custom_target(
    copy-compile-commands ALL
    ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(${EXECUTABLE_NAME} ${SOURCES})

target_link_libraries(${EXECUTABLE_NAME} ${PNG_LIBRARY} ${JPEG_LIBRARY})

