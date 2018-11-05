#include <stdio.h>
#include "math.h"
int * leak()
{
	return new int();
}

int main()
{
    math::vec3 v(1,2,3);
    
    int * l = leak();
    //cheking in bad code to test CI
    a=1;

    printf("Yo! %f \n",v.len());
    
    return 0;
}
