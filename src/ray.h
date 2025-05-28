#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    private:
        point3 orig;
        vec3 dir;

    public:
        // empty constructor
        ray() {}

        // constructor with an origin and a direction vector called orig and dir
        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

        // the origin() method used on the ray class returns the orig
        const point3& origin() const { return orig; }

        // the direction() method used on the ray class returns the dir
        const vec3& direction() const { return dir; }

        // linear interpolation for the at() method.
        // ray.at(t) gives the position of the ray at time t given origin and direction.
        point3 at(double t) const {
            return orig + t*dir;
        }
};

#endif