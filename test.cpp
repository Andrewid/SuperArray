#define CATCH_CONFIG_MAIN //
// 
#include "catch.hpp"
#include "SuperArray.h"

TEST_CASE("1) Test constructor")
{
    INFO("Testing SuperArray Class with regular indexes");
    int low = 0;
    int cap = 5;
    int high = low + cap -1;

    SuperArray sa(low, cap);
    for (int i = low; i <= high; i++){        
        sa[i] = i +20;
    }
    SECTION("Test #1: Constructor"){
        REQUIRE(arrayToString(sa) == "20 21 22 23 24");

    }
}

