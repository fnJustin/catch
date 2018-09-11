#include <stdio.h>
#include "math.h"

int main()
{
    math::vec3 v(1,2,3);
    
    printf("Yo! %f \n",v.len());
    
    return 0;
}
