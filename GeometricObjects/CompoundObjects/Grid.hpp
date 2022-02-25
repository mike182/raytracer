#ifndef __GRID_HPP__
#define __GRID_HPP__

#include "Compound.hpp"
#include "ShadeRec.hpp"
#include "Mesh.hpp"

class Grid: public Compound {
public:

    Grid(void);
    Grid(Mesh* m_ptr);
    Grid(const Grid& rg);
    virtual Grid* clone(void) const;
    virtual ~Grid(void);

    Grid& operator= (const Grid& rhs);

    virtual BBox get_bounding_box(void);
    void read_flat_triangles(char* file_name);
    void read_smooth_triangles(char* file_name);
    void tessellate_flat_sphere(const int horizontal_steps, const int vertical_steps);
    // void tessellate_smooth_sphere(const int horizontal_steps, const int vertical_steps);
    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    void setup_cells(void);
    void reverse_mesh_normals(void);
    void store_material(Material* material, const int index);

private:
    Point3D find_min_bounds(void);
    Point3D find_max_bounds(void);
    void read_ply_file(char* file_name, const int triangle_type);
    void compute_mesh_normals(void);

private:
    std::vector<GeometricObject*> cells; // grid of cells
    int nx, ny, nz; // number of cells in the x, y, and z directions
    BBox bbox; // bounding box
    Mesh* mesh_ptr; // holds triangle data
    bool reverse_normal; // some PLY files have normals that point inwards
};

inline void Grid::reverse_mesh_normals(void) {
    reverse_normal = true;
}

// stores the material in the specified object
// this is called from the Rosette and Archway classes, which inherit from Grid
inline void Grid::store_material(Material* material_ptr, const int index) {
    objects[index]->set_material(material_ptr);
}

#endif // __GRID_HPP__
