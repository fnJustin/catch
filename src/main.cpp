#include <stdio.h>
#include "math.h"

class Job
{
    
};

class JobQueue
{
    void Push(Job * j);
    Job * Pop();
};

void worker1()
{
    
}

int main()
{
    
    std::thread t(&worker1);
    math::vec3 v(1,2,3);
    
    printf("Yo! %f \n",v.len());
    if(t.joinable())
        t.join();
    
    return 0;
}
