#include "catch.hpp"
#include <stack.hpp>

TEST_CASE( "init stack", "[stack]"){
    
    SECTION( "init with no param" ){
        Stack<int> si1{};
        
        REQUIRE( si1.count() == 0 );
        REQUIRE( si1.empty() == true );
    }
    
    SECTION( "init with one param" ){
        Stack<int> si2(5);
        
        REQUIRE( si2.count() == 0 );
        REQUIRE( si2.empty() == true );
        
    }

    SECTION( "init with full param" ){
        Stack<int> si3(10, 5, new int[5]{1,2,3,4,5});
        
        REQUIRE( si3.count() == 5 );
        REQUIRE( si3.empty() == false );
    }
    
    SECTION( "init with copy" ){
        Stack<int> si4(10, 5, new int[5]{1,2,3,4,5});
        Stack<int> si5(si4);
        
        REQUIRE( si5.count() == 5 );
        REQUIRE( si5.empty() == false );
        REQUIRE( si5.top() == 5);
    }

    SECTION( "init with move" ){
        Stack<int> si6(10, 5, new int[5]{1,2,3,4,5});
        Stack<int> si7(move(si6));
        
        REQUIRE( si6.empty() == true );
        REQUIRE( si6.count() == 0 );
        REQUIRE( si7.count() == 5 );
        REQUIRE( si7.empty() == false );
        REQUIRE( si7.top() == 5);
    }
    
    SECTION( "init with initlist" ){
        Stack<int> si8{1,2,3,4,5,6,7};
        int x = si8.top();
        si8.pop();
        int y = si8.top();
        
        REQUIRE( x == 7 );
        REQUIRE( y == 6 );
        REQUIRE( si8.count() == 6 );
        
    }
}