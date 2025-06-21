#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "RecursionTypes.hpp"

TEST_CASE("Factorial function tests", "[factorial]") {
    RecursionTypes rt;
    
    SECTION("Base cases") {
        REQUIRE(rt.factorial(0) == 1);
        REQUIRE(rt.factorial(1) == 1);
    }
    
    SECTION("Small positive numbers") {
        REQUIRE(rt.factorial(2) == 2);
        REQUIRE(rt.factorial(3) == 6);
        REQUIRE(rt.factorial(4) == 24);
        REQUIRE(rt.factorial(5) == 120);
    }
    
    SECTION("Larger numbers") {
        REQUIRE(rt.factorial(6) == 720);
        REQUIRE(rt.factorial(7) == 5040);
        REQUIRE(rt.factorial(10) == 3628800);
    }
}

TEST_CASE("GCD function tests", "[gcd]") {
    RecursionTypes rt;
    
    SECTION("Basic cases") {
        REQUIRE(rt.gcd(12, 8) == 4);
        REQUIRE(rt.gcd(8, 12) == 4);
        REQUIRE(rt.gcd(17, 13) == 1);
    }
    
    SECTION("Same numbers") {
        REQUIRE(rt.gcd(5, 5) == 5);
        REQUIRE(rt.gcd(1, 1) == 1);
    }
    
    SECTION("One is 1") {
        REQUIRE(rt.gcd(1, 7) == 1);
        REQUIRE(rt.gcd(15, 1) == 1);
    }
    
    SECTION("Larger numbers") {
        REQUIRE(rt.gcd(48, 18) == 6);
        REQUIRE(rt.gcd(1071, 462) == 21);
        REQUIRE(rt.gcd(270, 192) == 6);
    }
}

TEST_CASE("Fibonacci function tests", "[fibonacci]") {
    RecursionTypes rt;
    
    SECTION("Base cases") {
        REQUIRE(rt.fibonacci(0) == 0);
        REQUIRE(rt.fibonacci(1) == 1);
    }
    
    SECTION("Small numbers") {
        REQUIRE(rt.fibonacci(2) == 1);
        REQUIRE(rt.fibonacci(3) == 2);
        REQUIRE(rt.fibonacci(4) == 3);
        REQUIRE(rt.fibonacci(5) == 5);
        REQUIRE(rt.fibonacci(6) == 8);
        REQUIRE(rt.fibonacci(7) == 13);
    }
    
    SECTION("Medium numbers") {
        REQUIRE(rt.fibonacci(10) == 55);
        REQUIRE(rt.fibonacci(15) == 610);
        REQUIRE(rt.fibonacci(20) == 6765);
    }
}

TEST_CASE("Ackermann function tests", "[ackermann]") {
    RecursionTypes rt;
    
    SECTION("m = 0 cases") {
        REQUIRE(rt.ackermann(0, 0) == 1);
        REQUIRE(rt.ackermann(0, 1) == 2);
        REQUIRE(rt.ackermann(0, 5) == 6);
        REQUIRE(rt.ackermann(0, 10) == 11);
    }
    
    SECTION("m = 1 cases") {
        REQUIRE(rt.ackermann(1, 0) == 2);
        REQUIRE(rt.ackermann(1, 1) == 3);
        REQUIRE(rt.ackermann(1, 2) == 4);
        REQUIRE(rt.ackermann(1, 5) == 7);
    }
    
    SECTION("m = 2 cases") {
        REQUIRE(rt.ackermann(2, 0) == 3);
        REQUIRE(rt.ackermann(2, 1) == 5);
        REQUIRE(rt.ackermann(2, 2) == 7);
        REQUIRE(rt.ackermann(2, 3) == 9);
    }
    
    SECTION("m = 3 cases (small n only)") {
        REQUIRE(rt.ackermann(3, 0) == 5);
        REQUIRE(rt.ackermann(3, 1) == 13);
        REQUIRE(rt.ackermann(3, 2) == 29);
        REQUIRE(rt.ackermann(3, 3) == 61);
    }
}