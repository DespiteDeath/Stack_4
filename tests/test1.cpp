#include "catch.hpp"
#include <stack.hpp>

// testing push(), count(), reinitializeMemory()

TEST_CASE("when you add elements count_ are increases", "[stack]" ){
    
    Stack<int> si( 2 );
    
    REQUIRE( si.count() == 0 );
    
    SECTION( "adding element in si" ){
        si.push( 1 );
        
        REQUIRE( si.count() == 1 );
    }
    
    SECTION( "adding two element in si" ){
        si.push ( 0 );
        si.push ( -1 );
        
        REQUIRE( si.count() == 2 );
    }
    
    SECTION( "adding more than two elements -> reinitialization of memory" ){
        si.push( 0 );
        si.push( 1 );
        si.push( 2 );
        
        REQUIRE( si.count() == 3 );
    }
}