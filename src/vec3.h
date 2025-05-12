#ifndef VEC3_H      // quick check to see if vec3 has already been defined or not.
    #define VEC3_H      // if not defined --> define the vec3 class

    #include<cmath>
    #include<iostream>

    class vec3 {
        public:
        double e[3];                    //64 bit high precision where e is a 3D vector

        // default constructor
        vec3() : e{0, 0, 0} {}

        // specifiable constructor.
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}
    
        // define methods, i.e. functions x(), y(), and z() to return respective entries from list.
        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }
    
        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        double  operator[](int i) const { return e[i]; }        // this is just a simple way to index
        double& operator[](int i ) { return e[i]; }             // the ampersand & returns a reference, allowing direct modification of elements
    
        vec3& operator+=(const vec3& v){
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }
        
        vec3& operator*=(double a){
            e[0] *= a;
            e[1] *= a;
            e[2] *= a;

            return *this;
        }

        vec3& operator/=(double a){
            return *this *= 1/a;
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

        double length() const {
            return std::sqrt(length_squared());
        }
    };

    using point3 = vec3;

    inline std::ostream& operator<<(std::ostream& out, const vec3& v){
        return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
    }

    inline vec3 operator+(const vec3& u, const vec3& v){
        return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
    }

    inline vec3 operator-(const vec3& u, const vec3& v){
        return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
    }

    inline vec3 operator*(const vec3& u, const vec3& v){
        return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
    }

    inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
    }

    inline vec3 operator*(const vec3& v, double t) {
        return t * v;
    }

    inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
    }

    inline double dot(const vec3& u, const vec3& v){
        return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
    }

    inline vec3 cross(const vec3& u, const vec3& v) {
        return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                    u.e[2] * v.e[0] - u.e[0] * v.e[2],
                    u.e[0] * v.e[1] - u.e[1] * v.e[0]);
    }

    inline vec3 unit_vector(const vec3& u){
        return u / u.length();
    }

#endif