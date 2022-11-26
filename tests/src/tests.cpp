#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "catch.hpp"
extern "C" {
#include "duration.h"
}

// See Catch2's documentation:
// https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. Opgave d

// Test cases for exercise a, b, c:
TEST_CASE("a, b, c") {
    Duration d0;
    REQUIRE(d0.getDuration() == 0);
    Duration d1(10);
    REQUIRE(d1.getDuration() == 10);
    Duration d2(254);
    REQUIRE(d2.getDuration() == 254);
}

// Test cases for exercise e
TEST_CASE("tick") {
    Duration d;
    REQUIRE(d.getDuration() == 0);
    for (int i = 0; i < 10; i++) {
        d.tick();
    }
    REQUIRE(d.getDuration() == 10);
    d.tick();
    REQUIRE(d.getDuration() == 11);
}
// Test cases for exercise f
TEST_CASE("adding time") {
    Duration d;
    REQUIRE(d.getDuration() == 0);
    d.tick(10);
    REQUIRE(d.getDuration() == 10);
    d.tick(3);
    REQUIRE(d.getDuration() == 13);
}
// Test cases for exercise g
TEST_CASE("alarm") {
    Duration d;
    d.setAlarm(10);
    REQUIRE(!d.tick());
    REQUIRE(d.tick(10));
    d.setAlarm(3);
    REQUIRE(!d.tick(4));
}