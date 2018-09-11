#include "math.h"


using namespace math;

float vec3::dot(vec3 &a){
    return x*a.x+y*a.y+z*a.z;
}

vec3 vec3::cross(vec3 &b)
{
    return vec3(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x);
}

float vec3::lenSq(){
    return x*x+y*y+z*z;
}

float vec3::len(){
    return sqrt(lenSq());
}
float vec3::normalise(){
    float len = lenSq();
    if(len!=0.0f)
    {
        len = sqrt(len);
        x=x/len;
        y=y/len;
        z=z/len;
    }
    
    return len;
}
vec3 vec3::operator+(const vec3 &b) const
{
    return vec3(x + b.x, y + b.y, z + b.z);
}
vec3 vec3::operator-(const vec3 &b) const
{
    return vec3(x - b.x, y - b.y, z - b.z);
}
vec3 vec3::operator*(float b) const
{
    return vec3(x*b, y*b, z*b);
}
vec3 vec3::operator/(float b) const
{
    return vec3(x / b, y / b, z / b);
}
bool vec3::operator==(const vec3 &b) const
{
    return (x==b.x && y==b.y && z==b.z);
}

vec3 &vec3::operator=(vec3 &b)
{
    x = b.x;
    y = b.y;
    z = b.z;
    return *this;
}

