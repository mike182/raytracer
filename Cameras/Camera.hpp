#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include "Point3D.hpp"
#include "Vector3D.hpp"

class World;

class Camera {
public:
    Camera(void);
    Camera(const Camera& cam);
    virtual Camera* clone(void) const = 0;
    virtual ~Camera(void);

    Camera& operator=(const Camera& rhs);

    virtual void render_scene(const World& w) = 0;

    void set_eye(const Point3D& p);
    void set_eye(const float x, const float y, const float z);
    void set_lookat(const Point3D& p);
    void set_lookat(const float x, const float y, const float z);
    void set_up_vector(const Vector3D& u);
    void set_up_vector(const float x, const float y, const float z);
    void set_roll(const float ra);
    void set_exposure_time(const float exposure);

    void compute_uvw(void);

public:
    Point3D eye;
    Point3D lookat;
    float ra;
    Vector3D u, v, w;
    Vector3D up;
    float exposure_time;
};

inline void Camera::set_eye(const Point3D& p) {
    eye = p;
}

inline void Camera::set_eye(const float x, const float y, const float z) {
    eye.x = x;
    eye.y = y;
    eye.z = z;
}

inline void Camera::set_lookat(const Point3D& p) {
    lookat = p;
}

inline void Camera::set_lookat(const float x, const float y, const float z) {
    lookat.x = x;
    lookat.y = y;
    lookat.z = z;
}

inline void Camera::set_up_vector(const Vector3D& u) {
    up = u;
}

inline void Camera::set_up_vector(const float x, const float y, const float z) {
    up.x = x;
    up.y = y;
    up.z = z;
}

inline void Camera::set_exposure_time(const float exposure) {
    exposure_time = exposure;
}

#endif // __CAMERA_HPP__
