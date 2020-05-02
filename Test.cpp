#include "doctest.h"
#include "solver.hpp"
#include <string>
#define EPS 0.0001
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

TEST_CASE("solving polnomial equation") 
{
	RealVariable x;
	CHECK(solve(2*x+(x^2)+1 == 0) == -1);
	CHECK(solve(6*(x^2) == 1.5) == 0.5);
	CHECK(solve(5*(x^2)-5 == 10) == sqrt(3));
	CHECK(solve((x^2)-4 == 12) == 4);
	CHECK(solve((x^2) == 10) == sqrt(10));
	CHECK(solve(0 == 2*(x^2)) == 0);
	CHECK(solve((x^2)-x == 12) == 4);
	CHECK(solve((x^2) == 8) == sqrt(8));
	CHECK(solve(0.1*(x^2)-1 == 0) == sqrt(10));
	CHECK(solve(2*(x^2) == 9) == sqrt(4.5));
}

TEST_CASE("throw exceptions") {
	RealVariable x;
	CHECK_THROWS(solve((x^2) == -16));
	CHECK_THROWS(solve((x^2)-x == -16));
	CHECK_THROWS(solve((x^2)-5 == -16));
	CHECK_THROWS(solve((x^2)+3*x == -9));
	CHECK_THROWS(solve(3*(x^2)-2*x == -15));
	CHECK_THROWS(solve(-3*(x^2) == 30));
	CHECK_THROWS(solve((x^2) == -1));
	CHECK_THROWS(solve((x^2)-10*x == -26));
	CHECK_THROWS(solve((x^2)-15 == -16));
	CHECK_THROWS(solve((-1*x^2) == -16));

}

TEST_CASE("solving linear equation with real numbers") {
	ComplexVariable x;
	CHECK(solve(2*x-4 == 10) == std::complex<double>(7,0));
	CHECK(solve(6*x == 3) == std::complex<double>(0.5,0));
	CHECK(solve(5*x-5 == 10) == std::complex<double>(3,0));
	CHECK(solve(6*x-4 == 8) == std::complex<double>(2,0));
	CHECK(solve(4-2*x == 10) == std::complex<double>(3,0));
	CHECK(solve(10 == 2*x-4) == std::complex<double>(7,0));
	CHECK(solve(10*x-5 == 10) == std::complex<double>(1.5,0));
	CHECK(solve(3*x-1 == 8) == std::complex<double>(3,0));
	CHECK(solve(0.2*x-4 == 2) == std::complex<double>(30,0));
	CHECK(solve(5*x-1 == 9) == std::complex<double>(2,0));
}

TEST_CASE("various complex equation") {
	ComplexVariable x;
	CHECK(solve(2*x-1 == 0) == std::complex<double>(0.5,0));
	CHECK(solve(6*x+5 == 1.5) == std::complex<double>(-7/12,0));
	CHECK(solve(5*(x^2) == (x^2)-5) == std::complex<double>(0,sqrt(5)/2));
	CHECK(solve((x^2)-4 == 12) == std::complex<double>(4,0));
	CHECK(solve((x^2) == -25) == std::complex<double>(0,5));
	CHECK(solve(2 == 2*(x^2)) == std::complex<double>(1,0));
	CHECK(solve((x^2)-x == -12) == std::complex<double>(0.5,sqrt(47)/2));
	CHECK(solve((x^2)+2 == -8) == std::complex<double>(0,sqrt(10)));
	CHECK(solve(0.1*x == 0) == std::complex<double>(0,0));
	CHECK(solve((x^2)+3 == -1) == std::complex<double>(0,2));
	CHECK(solve(-2*x+(x^2)+1 == (x^2)) == std::complex<double>(0.5,0));
	CHECK(solve(6*2*x == 6*(x^2)) == std::complex<double>(0,0));
	CHECK(solve((x^2)+5*x == -10) == std::complex<double>(-2.5,sqrt(15)/2));
	CHECK(solve((x^2)-4 == 12) == std::complex<double>(4,0));
	CHECK(solve((x^2) == -121) == std::complex<double>(0,11));
	CHECK(solve(-4 == -2*(x^2)) == std::complex<double>(sqrt(2),0));
	CHECK(solve((x^2) == -1) == std::complex<double>(0,1));
	CHECK(solve((x^2) == 1) == std::complex<double>(1,0));
	CHECK(solve((x^2)-2*x == 3) == std::complex<double>(1,sqrt(2)));
	CHECK(solve(x == 9) == std::complex<double>(9,0));
}

TEST_CASE("solve linear equations")
{
    RealVariable x;

    CHECK(abs(solve(2*x-8==10)-9)<EPS);
    CHECK(abs(solve(2*x-5+50==10)-(-17.5)<EPS));
    CHECK(abs(solve(x*2-8==10)-9)<EPS);
    CHECK(abs(solve((5*5)*x-20==10)-1.2)<EPS);
    CHECK(abs(solve(7*x-4/2 == 47)-7) < EPS);
    CHECK(abs(solve(2*x+2*x == 4)-1) < EPS);
    CHECK(abs(solve(-1*x-3 == -2*x) - 3 ) < EPS);
    CHECK(abs(solve(-2*x-3 == -6*x) - 0.75) < EPS);
    CHECK(abs(solve(2*x-8 == -8)) < EPS);
    CHECK(abs(solve(x*2 + 8==12) - 2 ) < EPS);
    CHECK(abs(solve(2*x-4 == 10)-7 ) < EPS);
    CHECK(abs(solve(2*x == 10) - 5) < EPS);
    CHECK(abs(solve(7*x-4/2 == 47) - 7 ) < EPS);
    CHECK(abs(solve(2*x+2*x == 4) - 1 ) < EPS);
    CHECK(abs(solve(x-3-3-3 == -2*x) - 3 ) < EPS);
    CHECK(abs(solve(89*x-95 == -6*x) - 1.0) < EPS);
    CHECK(abs(solve(2*x+12 == -8) - (-10) ) < EPS);
    CHECK(abs(solve(x*2 + 4==12) - 4 ) < EPS);
    CHECK(abs(solve(2*x-4 == 10)-7 ) < EPS);
    CHECK(abs(solve(2*x == 4) - 2) < EPS);
    CHECK(abs(solve(7*x-4/2 == 47) - 7 ) < EPS);
    CHECK(abs(solve(2*x+2*x == 4) - 1 ) < EPS);
    CHECK(abs(solve(-8 == -2*x) - 4 ) < EPS);//x in right side
    CHECK(abs(solve(-20*x == -6*x)) < EPS);//x is zero
    CHECK(abs(solve(2*x+12 == -8) - (-10) ) < EPS);
    CHECK(abs(solve(x*2 + 4==12) - 4 ) < EPS);
    CHECK(abs(solve(2*x-4 == 10)-7 ) < EPS);
    CHECK(abs(solve(2*x == 4) - 2) < EPS);
    CHECK(abs(solve(70*x-(100*2*3) == -670) -(-1)) < EPS);
    CHECK(abs(solve(2*x+2*x == 4) - 1 ) < EPS);
    CHECK(abs(solve(-10*x-32 == -2*x) - (-4) ) < EPS);
    CHECK(abs(solve(80*x-302 == 78*x) - 151) < EPS);
    CHECK(abs(solve(2*x+12 == -8) - (-10) ) < EPS);
    CHECK(abs(solve(x*2 + 16==12) - (-2) ) < EPS);

}

TEST_CASE("solve square equations")
{
    RealVariable x;

    CHECK( abs(solve(2*(x^2) == 8 ) - (-2) ) < EPS);//Two possible solutions - +2 or -2
    CHECK( abs(solve(3*(x^2)-12*x==0) ) < EPS);
    CHECK( abs(solve(3*(x^2)-12*x==0) -4) < EPS);
    CHECK( abs(solve(x^2+2*x-8==0) - 2) < EPS);
    CHECK( abs(solve(x^2+2*x-8==0) - (-4)) < EPS);
    CHECK( abs(solve(x^2+3*x-18) - 3 ) < EPS);
    CHECK( abs(solve(x^2+3*x-18) - (-6) ) < EPS);
    CHECK( abs(solve(2*(x^2)-9*x == -9) - 1.5 ) < EPS);
    CHECK( abs(solve(2*(x^2)-9*x == -9) - 3 ) < EPS);
    
}