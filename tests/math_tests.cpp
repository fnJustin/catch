#include "../thirdparty/catch/catch.h"
#include "../src/math.h"

#include <ostream>

//helpers for expansion macro
namespace std {
    std::ostream& operator << ( std::ostream& os, math::vec3 const& value ) {
        return os << "("<< value.x << " " <<value.y << " "<< value.z<<")";
      
    }
}

SCENARIO( "vec3 supports operator overloads", "[vec3]" ) {
    GIVEN("vec3 A(-1,1,-1) and B(2,-1,2)"){
        math::vec3 A(-1,1,-1);
        math::vec3 B(2,-1,2);
        
        WHEN("A is added to B"){
            math::vec3 C = A+B;
            
            THEN("The resultant is 1,0,1"){
                
                math::vec3 result(1,0,1);
                REQUIRE(C == result);
            }
        }
        
        WHEN("A is subtracted from B"){
            math::vec3 C = B-A;
            THEN("The resultant is 3,-2,3"){
                
                math::vec3 result(3,-2,3);
                
                REQUIRE(C == result);
            }
        }
        
        WHEN("A is multiplied by 2"){
            math::vec3 C = A * 2;
            
            THEN("The resultant is -2,2,-2"){
                math::vec3 result(-2,2,-2);
                REQUIRE(C == result);
            }
        }
        
        WHEN("A is divided by 2"){
            math::vec3 C = A / 2;
            
            THEN("The resultant is -0.5,0.5,-0.5"){
                math::vec3 result(-0.5,0.5,-0.5);
                REQUIRE(C == result);
            }
        }
        
    }
}

TEST_CASE( "aproximatlyEqual works", "[vec3]" ) {
    REQUIRE( math::approximatelyEqual(1,1) == true );
    REQUIRE( math::approximatelyEqual(0.999,1) == true );
    REQUIRE( math::approximatelyEqual(0.0,-0.0001) == true );
    REQUIRE( math::approximatelyEqual(0.0, 0.01) == false );
    REQUIRE( math::approximatelyEqual(1000.0, 1000.01) == false );
}

TEST_CASE( "Vector lenSq is correct", "[vec3]" ) {
    REQUIRE( math::vec3(2,2,2).lenSq() == 12 );
    REQUIRE( math::vec3(1,10,1).lenSq() == 102 );
    REQUIRE( math::vec3(-11,10,-12).lenSq() == 365 );
    
    
}

TEST_CASE( "Vector length is correct", "[vec3]" ) {
    REQUIRE( math::approximatelyEqual(math::vec3(0.707,0.707,0).len(), 1) );
    REQUIRE( math::vec3(2,3,6).len() == 7 );
    
}

TEST_CASE( "Vector dot is correct", "[vec3]" ) {
    math::vec3 v1 = math::vec3(1,0,0);
    math::vec3 v2 = math::vec3(-1,0,0);
    //these are parrellel
    REQUIRE( v1.dot(v2) == -1.0f );
    
}

TEST_CASE( "Vector cross is correct", "[vec3]" ) {
    math::vec3 v1 = math::vec3(1,0,0);
    math::vec3 v2 = math::vec3(0,1,0);
    //right angle
    math::vec3 v3 = math::vec3(0,0,1);
    
    REQUIRE( v1.cross(v2) == v3 );
}

