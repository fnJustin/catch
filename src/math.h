#ifndef math_h
#define math_h


#include <math.h>
namespace math
{
    static bool approximatelyEqual(float a, float b){
        if(fabs(a - b) <= 0.001)
        {
            return true;
        }
        return false;
    }

    class vec3
    {
    public:
        vec3(float xx = 0, float yy = 0, float zz = 0) : x(xx), y(yy), z(zz) {};
        float x,y,z;
        
        float dot(vec3 &a);
        vec3 cross(vec3 &b);
        float len();
        float lenSq();
        float normalise();
        
        vec3 operator+(const vec3 &b) const;
        vec3 operator-(const vec3 &b) const;
        vec3 operator*(const vec3 &b) const;
        vec3 operator/(const vec3 &b) const;
        
        vec3 operator*(float b) const;
        vec3 operator/(float b) const;
        bool operator==(const vec3 &b) const;
        vec3& operator=(vec3 &b);

       
    };
   
  
    
}

#endif
