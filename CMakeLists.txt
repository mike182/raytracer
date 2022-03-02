cmake_minimum_required(VERSION 3.19)

project(raytracer)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-std=c++17 -W -Wall -Werror -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-g3")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)
# find_package(SDL2)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(PNG REQUIRED)
# find_package(PNG)
find_package(JPEG REQUIRED)
# find_package(JPEG)

find_package(OpenMP REQUIRED)
# find_package(OpenMP)

set (SOURCES
  main.cpp
  # World
  World/World.cpp
  World/ViewPlane.cpp
  #BRDFs
  BRDFs/BRDF.cpp
  BRDFs/Lambertian.cpp
  BRDFs/GlossySpecular.cpp
  BRDFs/SV_Lambertian.cpp
  # Cameras
  Cameras/Camera.cpp
  Cameras/Orthographic.cpp
  Cameras/Pinhole.cpp
  # Graphics
  Graphics/Graphics.cpp
  Graphics/GuiSDL.cpp
  Graphics/ImgPNG.cpp
  # Graphics/ImgJPEG.cpp # WIP
  # Lights
  Lights/Light.cpp
  Lights/Ambient.cpp
  Lights/Directional.cpp
  Lights/PointLight.cpp
  Lights/AmbientOccluder.cpp
  Lights/AreaLight.cpp
  # Materials
  Materials/Material.cpp
  Materials/Matte.cpp
  Materials/Phong.cpp
  Materials/Emissive.cpp
  Materials/SV_Matte.cpp
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
  Tracers/RayCast.cpp
  Tracers/AreaLighting.cpp
  # Objects
  GeometricObjects/GeometricObject.cpp
  GeometricObjects/Instance.cpp
  GeometricObjects/Primitives/Plane.cpp
  GeometricObjects/Primitives/Sphere.cpp
  GeometricObjects/Primitives/Rectangle.cpp
  GeometricObjects/Primitives/OpenCylinder.cpp
  GeometricObjects/Primitives/Torus.cpp
  GeometricObjects/Primitives/OpenCone.cpp
  GeometricObjects/Primitives/Disk.cpp
  GeometricObjects/Primitives/Box.cpp
  # GeometricObjects/Primitives/Goursat.cpp # WIP
  GeometricObjects/Triangles/Triangle.cpp
  GeometricObjects/Triangles/SmoothTriangle.cpp
  GeometricObjects/Triangles/MeshTriangle.cpp
  GeometricObjects/Triangles/FlatMeshTriangle.cpp
  GeometricObjects/Triangles/SmoothMeshTriangle.cpp
  GeometricObjects/PartObjects/ConvexPartSphere.cpp
  GeometricObjects/CompoundObjects/Compound.cpp
  GeometricObjects/CompoundObjects/Grid.cpp
  GeometricObjects/CompoundObjects/SolidCylinder.cpp
  # Utilities
  Utilities/BBox.cpp
  Utilities/RGBColor.cpp
  Utilities/ShadeRec.cpp
  Utilities/Ray.cpp
  Utilities/Point2D.cpp
  Utilities/Point3D.cpp
  Utilities/Vector3D.cpp
  Utilities/Normal.cpp
  Utilities/Maths.cpp
  Utilities/Matrix.cpp
  Utilities/Mesh.cpp
  Utilities/ply.c
  )

set (SOURCES_SCENES
    # Custom
    # Scenes/BuildTest.cpp
    # Scenes/GeometricObjects.cpp
    # Scenes/000.cpp # single sphere
    # Scenes/001.cpp
    # Scenes/002.cpp

    # Chapter 03
    # Scenes/BuildCh03PageOneImage.cpp // OLD
    # Scenes/BuildFigure03.18.cpp # single sphere // OLD
    # Scenes/BuildFigure03.20a.cpp # sphere & plane // OLD
    # Scenes/archimedean_spirale.cpp

    # Chapter 04
    # Scenes/BuildFigure04.04.cpp # AA low res
    # Scenes/BuildFigure04.08.cpp # Checker3D plane

    Scenes/BuildFigure18.04.cpp # Rectangle AreaLight & Boxes

    # Spenes/BuildFigure23.07.cpp # Two Flat Triangles

    )

include_directories (
  .
  BRDFs/
  Cameras/
  Graphics/
  GeometricObjects/
  GeometricObjects/Primitives/
  GeometricObjects/Triangles/
  GeometricObjects/PartObjects/
  GeometricObjects/CompoundObjects/
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

# SDL2
# target_link_libraries(MyProject SDL2::Main SDL2::Net SDL2::Mixer SDL2::Image SDL2::TTF SDL2::GFX)

# target_link_libraries(${EXECUTABLE_NAME} PUBLIC OpenMP::OpenMP_CXX ${SDL2_LIBRARIES} ${PNG_LIBRARY} ${JPEG_LIBRARY})
target_link_libraries(${EXECUTABLE_NAME}
    PUBLIC OpenMP::OpenMP_CXX
    PUBLIC SDL2::SDL2
    PUBLIC PNG::PNG
    PUBLIC JPEG::JPEG)

