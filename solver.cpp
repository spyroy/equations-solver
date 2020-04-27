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
    return RealVariable(co1,x.power_1,co2,x.power_2,x.var,num);
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
    return RealVariable(co1,x.power_1,co2,x.power_2,x.var,num);
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
RealVariable solver::operator ^(const RealVariable& x, const double y){
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
        return RealVariable(co1,pow1,co2,pow2,x.var,num);
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
    if((x.cofficcient_2 < 0 && x.num < 0) || (x.cofficcient_2 > 0 && x.num > 0)){
        throw runtime_error("There is no real solution");
    }
    double ans1;
    double ans2;
    if(x.power_1 && x.power_2){
        if((pow(x.cofficcient_2,2))-(4*x.cofficcient_1*x.num) < 0)
            throw runtime_error("There is no real solution");
        else
        {
            ans1 = ((x.cofficcient_2*(-1)) + sqrt((pow(x.cofficcient_2,2))-(4*x.cofficcient_1*x.num)))/2*x.cofficcient_1;
            ans2 = ((x.cofficcient_2*(-1)) - sqrt((pow(x.cofficcient_2,2))-(4*x.cofficcient_1*x.num)))/2*x.cofficcient_1;
        }  
    }
    if(x.power_1 && !x.power_2){
        ans1 = (x.num*(-1))/x.cofficcient_1;
    }
    if(!x.power_1 && x.power_2){
        ans1 = sqrt((x.num*(-1))/x.cofficcient_2);
        ans2 = (sqrt((x.num*(-1))/x.cofficcient_2))*(-1);
    }
    if(!x.power_1 && !x.power_2){
        ans1 = x.num*(-1);
    }
    return ans1;
}

ComplexVariable solver::operator +(const ComplexVariable& c1, const ComplexVariable& c2){
    return ComplexVariable();
}
ComplexVariable solver::operator +(const ComplexVariable& c, const double x){
    return ComplexVariable();
}
ComplexVariable solver::operator +(const double x, const ComplexVariable& c){
    return ComplexVariable();
}
ComplexVariable solver::operator +(const ComplexVariable& c1, std::complex<double> c2){
    return ComplexVariable();
}
ComplexVariable solver::operator -(const ComplexVariable& c1, const ComplexVariable& c2){
    return ComplexVariable();
}
ComplexVariable solver::operator -(const ComplexVariable& c, const double x){
    return ComplexVariable();
}
ComplexVariable solver::operator -(const double x, const ComplexVariable& c){
    return ComplexVariable();
}
ComplexVariable solver::operator -(const ComplexVariable& c1, std::complex<double> c2){
    return ComplexVariable();
}
ComplexVariable solver::operator *(const ComplexVariable& c1, const ComplexVariable& c2){
    return ComplexVariable();
}
ComplexVariable solver::operator *(const ComplexVariable& c, const double x){
    return ComplexVariable();
}
ComplexVariable solver::operator *(const double x, const ComplexVariable& c){
    return ComplexVariable();
}
ComplexVariable solver::operator *(const ComplexVariable& c1, std::complex<double> c2){
    return ComplexVariable();
}
ComplexVariable solver::operator /(const ComplexVariable& c1, const ComplexVariable& c2){
    return ComplexVariable();
}
ComplexVariable solver::operator /(const ComplexVariable& c, const double x){
    return ComplexVariable();
}
ComplexVariable solver::operator /(const double x, const ComplexVariable& c){
    return ComplexVariable();
}
ComplexVariable solver::operator /(const ComplexVariable& c1, std::complex<double> c2){
    return ComplexVariable();
}
ComplexVariable solver::operator ^(const ComplexVariable& c1, const ComplexVariable& c2){
    return ComplexVariable();
}
ComplexVariable solver::operator ^(const ComplexVariable& c1, double x){
    return ComplexVariable();
}
ComplexVariable solver::operator ^(const double x, const ComplexVariable& c){
    return ComplexVariable();
}
ComplexVariable solver::operator ^(const ComplexVariable& c1, std::complex<double> c2){
    return ComplexVariable();
}
ComplexVariable solver::operator ==(const ComplexVariable& c1, const ComplexVariable& c2){
    return ComplexVariable();
}
ComplexVariable solver::operator ==(const ComplexVariable& c, const double x){
    return ComplexVariable();
}
ComplexVariable solver::operator ==(const double x, const ComplexVariable& c){
    return ComplexVariable();
}
ComplexVariable solver::operator ==(const ComplexVariable& c1, std::complex<double> c2){
    return ComplexVariable();
}

complex<double> solver::solve(ComplexVariable) {
    return complex<double>();
}