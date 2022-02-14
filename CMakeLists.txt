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
  BRDFs/SV_Lambertian.cpp
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
  Lights/AmbientOccluder.cpp
  # Materials
  Materials/Material.cpp
  Materials/Matte.cpp
  Materials/SV_Matte.cpp
  Materials/Phong.cpp
  # Samplers
  Samplers/Sampler.cpp
  Samplers/Regular.cpp
  Samplers/PureRandom.cpp
  Samplers/NRooks.cpp
  Samplers/Hammersley.cpp
  Samplers/Jittered.cpp
  Samplers/MultiJittered.cpp
  # Textures
  Textures/Texture.cpp
  Textures/ConstantColor.cpp
  Textures/Checker3D.cpp
  # Tracers
  Tracers/Tracer.cpp
  # Tracers/SingleSphere.cpp # old
  Tracers/MultipleObjects.cpp
  Tracers/RayCast.cpp
  # Objects
  GeometricObjects/GeometricObject.cpp
  GeometricObjects/Primitives/Plane.cpp
  GeometricObjects/Primitives/Sphere.cpp
  GeometricObjects/Primitives/Rectangle.cpp
  # Utilities
  Utilities/Constants.h
  Utilities/RGBColor.cpp
  Utilities/ShadeRec.cpp
  Utilities/Ray.cpp
  Utilities/Point2D.cpp
  Utilities/Point3D.cpp
  Utilities/Vector3D.cpp
  Utilities/Normal.cpp
  Utilities/Maths.cpp
  Utilities/Matrix.cpp
  Utilities/Image.cpp
  )

set (SOURCES_SCENES
    # Scenes/BuildTest.cpp

    # Chapter 03
    # Scenes/BuildCh03PageOneImage.cpp // OLD
    # Scenes/BuildFigure03.18.cpp # single sphere // OLD
    # Scenes/BuildFigure03.20a.cpp # sphere & plane // OLD
    # Scenes/000.cpp # single sphere
    # Scenes/001.cpp
    # Scenes/002.cpp
    # Scenes/archimedean_spirale.cpp

    # Chapter 04
    # Scenes/BuildFigure04.04.cpp # AA low res
    # Scenes/BuildFigure04.08.cpp # Checker3D plane
    )

include_directories (
  .
  BRDFs/
  Cameras/
  GeometricObjects/
  GeometricObjects/Primitives/
  Lights/
  Materials/
  Samplers/
  Textures/
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

