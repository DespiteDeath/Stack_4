#include "catch.hpp"
#include <stack.hpp>

TEST_CASE( "operator = ", "[stack]"){
    
    SECTION( "= with copy" ){
        Stack<int> si1(10, 5, new int[5]{1,2,3,4,5});
        Stack<int> si2 = si1;
        int x = si2.top();
        
        REQUIRE( x == 5 );
        REQUIRE( si1.count() == 5 );
        REQUIRE( si1.empty() == false );
        REQUIRE( si2.count() == 5 );
        REQUIRE( si2.empty() == false );

    }

    SECTION( "= with move" ){
        Stack<int> si3(10, 5, new int[5]{1,2,3,4,5});
        Stack<int> si4 = move(si3);
        int x = si4.top();
        
        REQUIRE( x == 5 );
        REQUIRE( si3.count() == 0 );
        REQUIRE( si3.empty() == true );
        REQUIRE( si4.count() == 5 );
        REQUIRE( si4.empty() == false );
        
    }
}