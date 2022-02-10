cmake_minimum_required(VERSION 3.1)

project(raytracer)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-std=c++17 -W -Wall -Werror -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_DEBUG "-g3")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PNG REQUIRED)
# find_package(JPEG REQUIRED)

set (SOURCES
  main.cpp
  # World
  World/World.cpp
  World/ViewPlane.cpp
  #BRDFs
  BRDFs/BRDF.cpp
  BRDFs/Lambertian.cpp
  BRDFs/GlossySpecular.cpp
  # Cameras
  Cameras/Camera.cpp
  Cameras/Orthographic.cpp
  Cameras/Pinhole.cpp
  # Lights
  Lights/Light.cpp
  Lights/Ambient.cpp
  Lights/Directional.cpp
  Lights/PointLight.cpp
  # Materials
  Materials/Material.cpp
  Materials/Matte.cpp
  Materials/Phong.cpp
  # Samplers
  Samplers/Sampler.cpp
  Samplers/Regular.cpp
  Samplers/PureRandom.cpp
  Samplers/NRooks.cpp
  Samplers/Hammersley.cpp
  Samplers/Jittered.cpp
  Samplers/MultiJittered.cpp
  # Tracers
  Tracers/Tracer.cpp
  # Tracers/SingleSphere.cpp # old
  Tracers/MultipleObjects.cpp
  Tracers/RayCast.cpp
  # Objects
  GeometricObjects/GeometricObject.cpp
  GeometricObjects/Plane.cpp
  GeometricObjects/Sphere.cpp
  GeometricObjects/Rectangle.cpp
  # Utilities
  # Utilities/Constants.h
  Utilities/RGBColor.cpp
  Utilities/ShadeRec.cpp
  Utilities/Ray.cpp
  Utilities/Point2D.cpp
  Utilities/Point3D.cpp
  Utilities/Vector3D.cpp
  Utilities/Normal.cpp
  Utilities/Maths.cpp
  Utilities/Image.cpp
  )

set (SOURCES_SCENES
    # Scenes/Custom/03.18.cpp # red sphere
    # Scenes/Custom/03.c00.cpp # two spheres & plane
    # Scenes/Custom/03.c01.cpp # multiple spheres
    # Scenes/Custom/03.c02.cpp # archimedean spirale sphere
    # Scenes/BuildTmp.cpp
    # Scenes/BuildCh03PageOneImage.cpp # multiple spheres
    # Scenes/BuildFigure03.18.cpp
    # Scenes/BuildFigure03.20a.cpp
    # Scenes/BuildFigure04.04.cpp
    # Scenes/BuildFigure04.08.cpp #
    # Scenes/BuildFigure05.13.cpp #
    # Scenes/BuildFigure14.15.cpp
    # Scenes/BuildFigure14.21.cpp # two spheres with directional light and matte material
    # Scenes/BuildFigure14.22.cpp # multiple spheres
    # Scenes/BuildFigure14.22.1.cpp # multiple spheres with Phong ???
    # Scenes/BuildFigure14.22.2.cpp # multiple spheres with Phong ???
    # Scenes/BuildFigure14.24.cpp # four spheres
    # Scenes/BuildFigure16.10a.cpp # two spheres & plan with Shadows
    Scenes/BuildCh16PageOneImage.cpp # multiple spheres with Phong
    )

include_directories (
  .
  BRDFs/
  Cameras/
  GeometricObjects/
  Lights/
  Materials/
  Samplers/
  Tracers/
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

add_executable(${EXECUTABLE_NAME} ${SOURCES} ${SOURCES_SCENES})

target_link_libraries(${EXECUTABLE_NAME} ${PNG_LIBRARY} ${JPEG_LIBRARY})

