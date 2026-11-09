#define CATCH_CONFIG_MAIN
#include "catch.hpp"



TEST_CASE("SEARCH", "[search]")
{
  SECTION("Test something", "[hello]"){
    REQUIRE( hello() == true);
  }
}


SCENARIO("Addition", "[add]")
{
  GIVEN ("Positive numbers"){
    int a = 5;
    int b = 8;
    REQUIRE (add(a, b) == 13);
    
    WHEN ("Add another number"){
      int c = 2;
      REQUIRE (add(b, c) == 10);
      REQUIRE (add(a, c) == 7);
    }

    WHEN ("Add negative number"){
      int c = -2; 
      REQUIRE (add(b, c) == 6);
      REQUIRE (add(a, c) == 3);
    }
  }
}
