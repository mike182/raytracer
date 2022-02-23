#include "Mesh.hpp"

Mesh::Mesh(void)
    : num_vertices(0),
    num_triangles(0)
{
}

// this doesn't handle the vertex_faces
Mesh::Mesh (const Mesh& m)
    : vertices(m.vertices),
    normals(m.normals),
    u(m.u),
    v(m.v),
    num_vertices(m.num_vertices),
    num_triangles(m.num_triangles)
{
}

Mesh::~Mesh(void) {
}

// this doesn't handle the vertex_faces
Mesh& Mesh::operator=(const Mesh& rhs) {
    if (this == &rhs)
        return *this;
    vertices = rhs.vertices;
    normals = rhs.normals;
    u = rhs.u;
    v = rhs.v;
    num_vertices = rhs.num_vertices;
    num_triangles = rhs.num_triangles;
    return *this;
}
