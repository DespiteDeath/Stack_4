#include "catch.hpp"
#include <stack.hpp>

TEST_CASE( "pop and top", "[stack]" ){
    Stack<char> sc(5);
    
    REQUIRE( sc.empty() == true );
    
    SECTION( "push" ){
        sc.push('a');
        
        REQUIRE( sc.count() == 1 );
        REQUIRE( sc.empty() == false);
    }
    
    SECTION( "top" ){
        sc.push('a');
        sc.push('b');
        char x = sc.top();
        
        REQUIRE( x == 'b');
        REQUIRE( sc.count() == 2 );
        REQUIRE( sc.empty() == false);
    }

    SECTION( "pop" ){
        sc.push('a');
        sc.push('b');
        sc.pop();
        char x = sc.top();
        
        REQUIRE( x == 'a');
        REQUIRE( sc.count() == 1 );
        REQUIRE( sc.empty() == false);
    }

}
