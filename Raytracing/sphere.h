#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"
//sphere derives from Hittable
class sphere : public hittable
{
public:
    sphere(point3 _center, double _radius, shared_ptr<material> _material)
        : center(_center), radius(_radius), mat(_material) {}
    //the overriden hit function from the base hittable class with specific sphere info
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        //ray origin to center
        vec3 oc = r.origin() - center;
        //quadratic equation coefficients
        auto a = r.direction().length_squared();
        auto half_b = dot(oc, r.direction());
        auto c = oc.length_squared() - radius * radius;

        auto discriminant = half_b * half_b - a * c;
        //NOTE, rec is not set when we return false and no hit
        if (discriminant < 0) return false;
        auto sqrtd = sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (-half_b - sqrtd) / a;
        if (!ray_t.surrounds(root)) {
            root = (-half_b + sqrtd) / a;
            if (!ray_t.surrounds(root))
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        //checking to see if we are inside the sphere and have to change the normal
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);
        rec.mat = mat;

        return true;
    }
private:
    //for now the sphere only has a center and a radius
    point3 center;
    double radius;
    shared_ptr<material> mat;
};
#endif