#include "doctest.h"
#include "solver.hpp"
#include <string>

using namespace std;
using namespace solver;

TEST_CASE("real '+' and real '*'") {
    RealVariable x;
    x = 2*x + 5;
    CHECK(x.cofficcient_1 == 2);
    CHECK(x.cofficcient_2 == 0);
    CHECK(x.power_1 == true);
    CHECK(x.power_2 == false);
    CHECK(x.num == 5);
    CHECK(x.is_equastion == false);
    CHECK(x.var == 'x');
    x = x + x;
    CHECK(x.cofficcient_1 == 4);
    CHECK(x.cofficcient_2 == 0);
    CHECK(x.power_1 == true);
    CHECK(x.power_2 == false);
    CHECK(x.num == 10);
    CHECK(x.is_equastion == false);
    CHECK(x.var == 'x');
    x = x*0;
    CHECK(x.cofficcient_1 == 0);
    CHECK(x.cofficcient_2 == 0);
    CHECK(x.power_1 == false);
    CHECK(x.power_2 == false);
    CHECK(x.num == 0);
    CHECK(x.is_equastion == false);
    CHECK(x.var == 'x');
    x = x+4+(x+x+x+x+x+x+x+x)*4;
    CHECK(x.cofficcient_1 == 0);
    CHECK(x.cofficcient_2 == 0);
    CHECK(x.power_1 == false);
    CHECK(x.power_2 == false);
    CHECK(x.num == 4);
    CHECK(x.is_equastion == false);
    CHECK(x.var == 'x');
    RealVariable y;
    y = y + 0;
    CHECK(y.cofficcient_1 == 1);
    CHECK(y.cofficcient_2 == 0);
    CHECK(y.power_1 == true);
    CHECK(y.power_2 == false);
    CHECK(y.num == 0);
    CHECK(y.is_equastion == false);
    CHECK(y.var == 'x');
    RealVariable z(3,true,3,true,'x',6);
    y = (y+z)+z;
    CHECK(y.cofficcient_1 == 7);
    CHECK(y.cofficcient_2 == 6);
    CHECK(y.power_1 == true);
    CHECK(y.power_2 == true);
    CHECK(y.num == 12);
    CHECK(y.is_equastion == false);
    CHECK(y.var == 'x');
    CHECK_THROWS(y = (y+z)*z);
}

TEST_CASE("real '-' and real '/'"){
    RealVariable x;
    x = 2/x - 5;
    CHECK(x.cofficcient_1 == 0.5);
    CHECK(x.cofficcient_2 == 0);
    CHECK(x.power_1 == true);
    CHECK(x.power_2 == false);
    CHECK(x.num == -5);
    CHECK(x.is_equastion == false);
    CHECK(x.var == 'x');
    x = x - x;
    CHECK(x.cofficcient_1 == 0);
    CHECK(x.cofficcient_2 == 0);
    CHECK(x.power_1 == false);
    CHECK(x.power_2 == false);
    CHECK(x.num == 0);
    CHECK(x.is_equastion == false);
    CHECK(x.var == 'x');
    CHECK_THROWS(x = x/0);
    x = x-4-(x+x+x+x+x+x+x+x)/4;
    CHECK(x.cofficcient_1 == 0);
    CHECK(x.cofficcient_2 == 0);
    CHECK(x.power_1 == false);
    CHECK(x.power_2 == false);
    CHECK(x.num == -4);
    CHECK(x.is_equastion == false);
    CHECK(x.var == 'x');
    RealVariable y;
    y = y - 0;
    CHECK(y.cofficcient_1 == 1);
    CHECK(y.cofficcient_2 == 0);
    CHECK(y.power_1 == true);
    CHECK(y.power_2 == false);
    CHECK(y.num == 0);
    CHECK(y.is_equastion == false);
    CHECK(y.var == 'x');
    RealVariable z(3,true,3,true,'x',6);
    y = (y-z)-z;
    CHECK(y.cofficcient_1 == -5);
    CHECK(y.cofficcient_2 == -6);
    CHECK(y.power_1 == true);
    CHECK(y.power_2 == true);
    CHECK(y.num == -12);
    CHECK(y.is_equastion == false);
    CHECK(y.var == 'x');
    CHECK(y.cofficcient_1 == -5);
    CHECK(y.cofficcient_2 == -6);
    CHECK(y.power_1 == true);
    CHECK(y.power_2 == true);
    CHECK(y.num == -12);
    CHECK(y.is_equastion == false);
    CHECK(y.var == 'x');
    CHECK_NOTHROW(y = (y-z)/z);
}

TEST_CASE("real '^' and real '=='"){
    RealVariable x;
    x = x^0;
    CHECK(x.cofficcient_1 == 0);
    CHECK(x.cofficcient_2 == 0);
    CHECK(x.power_1 == false);
    CHECK(x.power_2 == false);
    CHECK(x.num == 1);
    CHECK(x.is_equastion == false);
    CHECK(x.var == 'x');
    x = RealVariable(5,true,0,false,'x',2); // 5x+2
    x = x^2;
    CHECK(x.cofficcient_1 == 20);
    CHECK(x.cofficcient_2 == 25);
    CHECK(x.power_1 == true);
    CHECK(x.power_2 == true);
    CHECK(x.num == 4);
    CHECK(x.is_equastion == false);
    CHECK(x.var == 'x');
    CHECK_THROWS(x = x^2);
    CHECK_THROWS(x = x^3);
    x = x == 5*x;
    CHECK(x.cofficcient_1 == -80);
    CHECK(x.cofficcient_2 == -100);
    CHECK(x.power_1 == true);
    CHECK(x.power_2 == true);
    CHECK(x.num == -16);
    CHECK(x.is_equastion == true);
    CHECK(x.var == 'x');
}

TEST_CASE("real solve and combined"){
    RealVariable x;
    x = x*5 + 8*x + (x^2)/3 + 16;
    CHECK(x.cofficcient_1 == 13);
    REQUIRE(x.cofficcient_2 == doctest::Approx(0.33).epsilon(0.01));
    CHECK(x.power_1 == true);
    CHECK(x.power_2 == true);
    CHECK(x.num == 16);
    CHECK(x.is_equastion == false);
    CHECK(x.var == 'x');
    RealVariable y;
    double ans = solve((y^2) + 13*y + 16 == 5);
    REQUIRE(((ans == doctest::Approx(-12.09017).epsilon(0.01)) || (ans == doctest::Approx(-0.90983).epsilon(0.01))));
    ans = solve(x == 12);
    REQUIRE(((ans == doctest::Approx(-38.68984).epsilon(0.01)) || (ans == doctest::Approx(-0.310159).epsilon(0.01))));
}