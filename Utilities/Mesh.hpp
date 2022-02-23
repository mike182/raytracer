#ifndef __MESH_HPP__
#define __MESH_HPP__

#include "Point3D.hpp"
#include "Normal.hpp"
#include <vector>

class Mesh {
public:
    std::vector<Point3D> vertices; // mesh vertices
    std::vector<Normal> normals; // average normal at each vertex
    std::vector<float> u; // u texture coordinate at each vertex
    std::vector<float> v; // v texture coordinate at each vertex
    std::vector<std::vector<int>> vertex_faces; // the triangles shared by each vertex
    int num_vertices; // number of vertices
    int num_triangles; // number of triangles

    Mesh(void);
    Mesh(const Mesh& m);
    ~Mesh(void);

    Mesh& operator=(const Mesh& rhs);
};

#endif // __MESH_HPP__
