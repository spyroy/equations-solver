#include "solver.hpp"
#include <complex>
#include <iostream>

using namespace std;
using namespace solver;

RealVariable solver::operator +(const RealVariable& x, const RealVariable& y){
    if(x.var != y.var){
        throw runtime_error("please enter only one variable");
    }
    int pow;
    double co1=0;
    double co2=0;
    double num=0;
    bool pow1;
    bool pow2;
    co1 = x.cofficcient_1 + y.cofficcient_1;
    co2 = x.cofficcient_2 + y.cofficcient_2;
    if(co1 == 0){
        pow1 = false;
    }
    else{
        pow1 = true;
    }
    if(co2 == 0){
        pow2 = false;
    }
    else{
        pow2 = true;
    }
    num = x.num + y.num;
    return RealVariable(co1,pow1,co2,pow2,x.var,num);
}
RealVariable solver::operator +(const RealVariable& x, const double y){
    return RealVariable(x.cofficcient_1,x.power_1,x.cofficcient_2,x.power_2,x.var,x.num+y);
}
RealVariable solver::operator +(const double x, const RealVariable& y){
    return RealVariable(y.cofficcient_1,y.power_1,y.cofficcient_2,y.power_2,y.var,y.num+x);
}
RealVariable solver::operator -(const RealVariable& x, const RealVariable& y){
     if(x.var != y.var){
        throw runtime_error("please enter only one variable");
    }
    int pow;
    double co1=0;
    double co2=0;
    double num=0;
    bool pow1;
    bool pow2;
    co1 = x.cofficcient_1 - y.cofficcient_1;
    co2 = x.cofficcient_2 - y.cofficcient_2;
    if(co1 == 0){
        pow1 = false;
    }
    else{
        pow1 = true;
    }
    if(co2 == 0){
        pow2 = false;
    }
    else{
        pow2 = true;
    }
    num = x.num - y.num;
    return RealVariable(co1,pow1,co2,pow2,x.var,num);
}
RealVariable solver::operator -(const RealVariable& x, const double y){
    return RealVariable(x.cofficcient_1,x.power_1,x.cofficcient_2,x.power_2,x.var,x.num-y);
}
RealVariable solver::operator -(const double x, const RealVariable& y){
    return RealVariable(y.cofficcient_1,y.power_1,y.cofficcient_2,y.power_2,y.var,y.num-x);
}
RealVariable solver::operator *(const RealVariable& x, const RealVariable& y){
    if(x.var != y.var){
        throw runtime_error("please enter only one variable");
    }
    if(x.power_2 || y.power_2){
        throw runtime_error("equation must be quadratic equation");
    }
    if((!x.power_1 && !x.power_2 && x.num == 0) || (!y.power_1 && !y.power_2 && y.num == 0)){
        return RealVariable(0,false,0,false,x.var,0);
    }
    double co1 = 0;
    double co2 = 0;
    bool pow1;
    bool pow2;
    double num;
    if(x.power_1 && y.power_1){
        co2 = (x.cofficcient_1 * y.cofficcient_1);
        co1 = (x.cofficcient_1 * y.num) + (x.num * y.cofficcient_1);
        if(co1 == 0){
            pow2=true;
            pow1=false;
        }
        else{
            pow2=true;
            pow1=true;
        }
    } 
    if(x.power_1 && !y.power_1){
        co1 = x.cofficcient_1 * y.num;
        pow2 = false;
        pow1 = true;
    }
    if(!x.power_1 && y.power_1){
        co1 = y.cofficcient_1 * x.num;
        pow2 = false;
        pow1 = true;
    }
    if(!x.power_1 && y.power_1){
        pow2 = false;
        pow1 = false;
    }
    num = (x.num * y.num);
    return RealVariable(co1,pow1,co2,pow2,x.var,num);
}
RealVariable solver::operator *(const RealVariable& x, const double y){
    if((!x.power_1 && !x.power_2 && x.num == 0) || y == 0){
        return RealVariable(0,false,0,false,x.var,0);
    }
    double co1 = 0;
    double co2 = 0;
    bool pow1;
    bool pow2;
    double num;
    co1 = x.cofficcient_1 * y;
    co2 = x.cofficcient_2 * y;
    pow1 = x.power_1;
    pow2 = x.power_2;
    num = x.num * y;
    return RealVariable(co1,pow1,co2,pow2,x.var,num);
}
RealVariable solver::operator *(const double x, const RealVariable& y){
    if((!y.power_1 && !y.power_2 && y.num == 0) || x == 0){
        return RealVariable(0,false,0,false,y.var,0);
    }
    double co1 = 0;
    double co2 = 0;
    bool pow1;
    bool pow2;
    double num;
    co1 = y.cofficcient_1 * x;
    co2 = y.cofficcient_2 * x;
    pow1 = y.power_1;
    pow2 = y.power_2;
    num = y.num * x;
    return RealVariable(co1,pow1,co2,pow2,y.var,num);
}
RealVariable solver::operator /(const RealVariable& x, const RealVariable& y){
    return RealVariable();
}
RealVariable solver::operator /(const RealVariable& x, const double y){
    if(y == 0){
        throw runtime_error("cannot divide '0'");
    }
    double co1 = 0;
    double co2 = 0;
    bool pow1;
    bool pow2;
    double num;
    co1 = x.cofficcient_1 / y;
    co2 = x.cofficcient_2 / y;
    pow1 = x.power_1;
    pow2 = x.power_2;
    num = x.num / y;
    return RealVariable(co1,pow1,co2,pow2,x.var,num);
}
//doesnt work well!!!
RealVariable solver::operator /(const double x, const RealVariable& y){
    double co1 = 0;
    double co2 = 0;
    bool pow1;
    bool pow2;
    double num;
    co1 = y.cofficcient_1 / x;
    co2 = y.cofficcient_2 / x;
    pow1 = y.power_1;
    pow2 = y.power_2;
    num = y.num / x;
    return RealVariable(co1,pow1,co2,pow2,y.var,num);
}
RealVariable solver::operator ^(const RealVariable& x, const RealVariable& y){
    return RealVariable();
}
//add negative power!!
RealVariable solver::operator ^(const RealVariable& x, const double y){
    if(!x.power_1 && !x.power_2){
        return RealVariable(0,false,0,false,x.var,x.num*y);
    }
    if(y > 2){
        throw runtime_error("equation must be quadratic equation");
    }
    double co1 = 0;
    double co2 = 0;
    bool pow1;
    bool pow2;
    double num;
    if(y == 0){
        num =1;
        return RealVariable(0,false,0,false,x.var,num);
    }
    if(y == 1){
        return x;
    }
    else{
        if(x.power_2 && y == 2){
            throw runtime_error("equation must be quadratic equation");
        }
        else{
            return x*x;
        }
    }
}
RealVariable solver::operator ^(const double x, const RealVariable& y){
    return RealVariable();
}
RealVariable solver::operator ==(const RealVariable& x, const RealVariable& y){
    RealVariable ans = x-y;
    ans.is_equastion = true;
    return ans;
}
RealVariable solver::operator ==(const RealVariable& x, const double y){
    RealVariable ans = x-y;
    ans.is_equastion = true;
    return ans;
}
RealVariable solver::operator ==(const double x, const RealVariable& y){
    RealVariable ans = x-y;
    ans.is_equastion = true;
    return ans;
}

double solver::solve(RealVariable x) {
    if(!x.is_equastion){
        throw runtime_error("this is not equation");
    }
    if((!x.power_1 && x.power_2 && x.cofficcient_2 < 0 && x.num < 0) || (!x.power_1 && x.power_2 && x.cofficcient_2 > 0 && x.num > 0)){
        throw runtime_error("There is no real solution");
    }
    if(!x.power_1 && !x.power_2 && x.num == 0){
        return INFINITY; // there are infinity number of solutions.
    }
    if(!x.power_1 && !x.power_2 && x.num != 0){
        throw runtime_error("There is no solution");
    }
    double ans1;
    double ans2;
    if(x.power_1 && x.power_2){
        if((pow(x.cofficcient_1,2))-(4*x.cofficcient_2*x.num) < 0)
            throw runtime_error("There is no real solution");
        else
        {
            double a = (pow(x.cofficcient_1,2));
            double b = (4*x.cofficcient_2*x.num);
            double c = sqrt(a-b);
            double d = 2*x.cofficcient_2;
            double e = (x.cofficcient_1*(-1));
            ans1 = ((e) + c)/d;
            ans2 = ((e) - c)/d;
            srand(time(NULL));
            int r =  rand()%2;
            if(r == 0)
                return ans1;
            else
                return ans2; 
        }  
    }
    if(!x.power_1 && x.power_2){
        ans1 = sqrt((x.num*(-1))/x.cofficcient_2);
        ans2 = (sqrt((x.num*(-1))/x.cofficcient_2))*(-1);
        srand(time(NULL));
        int r =  rand()%2;
        if(r == 0)
            return ans1;
        else
            return ans2; 
    }
    if(x.power_1 && !x.power_2){
        ans1 = (x.num*(-1))/x.cofficcient_1;
    }
    if(!x.power_1 && !x.power_2){
        ans1 = x.num*(-1);
    }  
    return ans1;
}

//complex

ComplexVariable solver::operator +(const ComplexVariable& c1, const ComplexVariable& c2){
    std::complex<double> x_2 = c1.x_2 + c2.x_2;
    std::complex<double> x_1 = c1.x_1 + c2.x_1;
    std::complex<double> c = c1.c + c2.c;
    return ComplexVariable(x_2,x_1,c);
}
ComplexVariable solver::operator +(const ComplexVariable& c, const double x){
    std::complex<double> c1 = c.c + x;
    return ComplexVariable(c.x_2,c.x_1,c1);
}
ComplexVariable solver::operator +(const double x, const ComplexVariable& c){
    std::complex<double> c1 = c.c + x;
    return ComplexVariable(c.x_2,c.x_1,c1);
}
ComplexVariable solver::operator +(const ComplexVariable& c1, std::complex<double> c2){
    return ComplexVariable(c1.x_2,c1.x_1,c1.c+c2);
}
ComplexVariable solver::operator +(std::complex<double> c2, const ComplexVariable& c1){
    return ComplexVariable(c1.x_2,c1.x_1,c1.c+c2);
}
ComplexVariable solver::operator -(const ComplexVariable& c1, const ComplexVariable& c2){
    std::complex<double> x_2 = c1.x_2 - c2.x_2;
    std::complex<double> x_1 = c1.x_1 - c2.x_1;
    std::complex<double> c = c1.c - c2.c;
    return ComplexVariable(x_2,x_1,c);
}
ComplexVariable solver::operator -(const ComplexVariable& c, const double x){
    std::complex<double> c1 = c.c - x;
    return ComplexVariable(c.x_2,c.x_1,c1);
}
ComplexVariable solver::operator -(const double x, const ComplexVariable& c){
    std::complex<double> c1 = x - c.c;
    return ComplexVariable(c.x_2,c.x_1,c1);
}
ComplexVariable solver::operator -(const ComplexVariable& c1, std::complex<double> c2){
    return ComplexVariable(c1.x_2,c1.x_1,c1.c-c2);
}
ComplexVariable solver::operator -(std::complex<double> c2, const ComplexVariable& c1){
    return ComplexVariable(c1.x_2,c1.x_1,c2-c1.c);
}
ComplexVariable solver::operator *(const ComplexVariable& c1, const ComplexVariable& c2){
    std::complex<double> x_2;
    std::complex<double> x_1;
    std::complex<double> c;
    if((c1.x_2 == complex<double>(0,0) && c1.x_1 == complex<double>(0,0) && c1.c == complex<double>(0,0)) || (c2.x_2 == complex<double>(0,0) && c2.x_1 == complex<double>(0,0) && c2.c == complex<double>(0,0))){
        return ComplexVariable(0.0,0.0,0.0);
    }
    if(c1.x_2 != complex<double>(0,0) && c2.x_2 != complex<double>(0,0)){
       throw runtime_error("equation must be quadratic equation");
    }
    if(c1.x_2 != complex<double>(0,0) && c2.x_1 != complex<double>(0,0)){
        throw runtime_error("equation must be quadratic equation");
    }
    if(c2.x_2 != complex<double>(0,0) && c1.x_1 != complex<double>(0,0)){
        throw runtime_error("equation must be quadratic equation");
    }
    if(c1.x_2 != complex<double>(0,0)){
        x_2 = c1.x_2 * c2.c;
        x_1 = c1.x_1 * c2.c;
        c = c1.c * c2.c;
    }
    if(c2.x_2 != complex<double>(0,0)){
        x_2 = c2.x_2 * c1.c;
        x_1 = c2.x_1 * c1.c;
        c = c2.c * c1.c;
    }
    if(c1.x_1 != complex<double>(0,0) && c2.x_1 != complex<double>(0,0)){
        x_2 = c1.x_1 * c2.x_1;
        x_1 = (c1.x_1 * c2.c) + (c1.c * c2.x_1);
        c = c1.c * c2.c;
    }
    else{
        x_2 = complex<double>(0,0);
        x_1 = complex<double>(0,0);
        c = c1.c * c2.c;
    }
    return ComplexVariable(x_2,x_1,c);
}
ComplexVariable solver::operator *(const ComplexVariable& c, const double x){
    std::complex<double> x_2 = c.x_2 * x;
    std::complex<double> x_1 = c.x_1 * x;
    std::complex<double> c1 = c.c * x;
    return ComplexVariable(x_2,x_1,c1);
}
ComplexVariable solver::operator *(const double x, const ComplexVariable& c){
    std::complex<double> x_2 = c.x_2 * x;
    std::complex<double> x_1 = c.x_1 * x;
    std::complex<double> c1 = c.c * x;
    return ComplexVariable(x_2,x_1,c1);
}
ComplexVariable solver::operator *(const ComplexVariable& c1, std::complex<double> c2){
    std::complex<double> x_2 = c1.x_2 * c2;
    std::complex<double> x_1 = c1.x_1 * c2;
    std::complex<double> c = c1.c * c2;
    return ComplexVariable(x_2,x_1,c);
}
ComplexVariable solver::operator *(std::complex<double> c2, const ComplexVariable& c1){
    std::complex<double> x_2 = c1.x_2 * c2;
    std::complex<double> x_1 = c1.x_1 * c2;
    std::complex<double> c = c1.c * c2;
    return ComplexVariable(x_2,x_1,c);
    return ComplexVariable();
}
ComplexVariable solver::operator /(const ComplexVariable& c1, const ComplexVariable& c2){
    return ComplexVariable();
}
ComplexVariable solver::operator /(const ComplexVariable& c, const double x){
    std::complex<double> x_2 = c.x_2 / x;
    std::complex<double> x_1 = c.x_1 / x;
    std::complex<double> c1 = c.c / x;
    return ComplexVariable(x_2,x_1,c1);
}
ComplexVariable solver::operator /(const double x, const ComplexVariable& c){
    std::complex<double> x_2 = x / c.x_2 ;
    std::complex<double> x_1 = x / c.x_1 ;
    std::complex<double> c1 = x / c.c ;
    return ComplexVariable(x_2,x_1,c1);
}
ComplexVariable solver::operator /(const ComplexVariable& c1, std::complex<double> c2){
    std::complex<double> x_2 = c1.x_2 / c2;
    std::complex<double> x_1 = c1.x_1 / c2 ;
    std::complex<double> c = c1.c / c2;
    return ComplexVariable(x_2,x_1,c);
}
ComplexVariable solver::operator /(std::complex<double> c2, const ComplexVariable& c1){
    std::complex<double> x_2 = c2 / c1.x_2;
    std::complex<double> x_1 = c2 / c1.x_1 ;
    std::complex<double> c = c2 / c1.c;
    return ComplexVariable(x_2,x_1,c);
}
ComplexVariable solver::operator ^(const ComplexVariable& c1, const ComplexVariable& c2){
    return ComplexVariable();
}
ComplexVariable solver::operator ^(const ComplexVariable& c1, double x){
    if(x == 0){
        return ComplexVariable(0.0,0.0,1.0);
    }
    if(x == 1){
        return c1;
    }
    if(x == 2 && c1.x_2 == complex<double>(0,0)){
        return c1*c1;
    }
    else{
        throw runtime_error("equation must be quadratic equation");
    }
}
ComplexVariable solver::operator ^(const double x, const ComplexVariable& c){
    return ComplexVariable();
}
ComplexVariable solver::operator ^(const ComplexVariable& c1, std::complex<double> c2){
    return ComplexVariable();
}
ComplexVariable solver::operator ==(const ComplexVariable& c1, const ComplexVariable& c2){
    return c1-c2;
}
ComplexVariable solver::operator ==(const ComplexVariable& c, const double x){
    return c-x;
}
ComplexVariable solver::operator ==(const double x, const ComplexVariable& c){
    return x-c;
}
ComplexVariable solver::operator ==(const ComplexVariable& c1, std::complex<double> c2){
    return c1-c2;
}
ComplexVariable solver::operator ==(std::complex<double> c2, const ComplexVariable& c1){
    return c2 - c1;
}

complex<double> solver::solve(ComplexVariable c) {
    std::complex<double> discriminant = ((c.x_1 * c.x_1)) - (std::complex<double>(4, 0) * c.x_2 * c.c);
    std::complex<double> ans = 0;
    if(c.x_2 == std::complex<double>(0, 0) && c.x_1 == std::complex<double>(0, 0)){
        throw runtime_error("This is not equation");
    }
    if (c.x_2 == std::complex<double>(0, 0)) {
        ans = (-c.c) / c.x_1;
    } else {
        discriminant = sqrt(discriminant);
        ans = (((-1.0) * c.x_1) + discriminant) / (2.0 * c.x_2);
    }
    return ans;
}
