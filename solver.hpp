#pragma once
#include <complex>
namespace solver {
    class RealVariable{
    public:
            char var;
            double cofficcient_1;
            double cofficcient_2;
            bool power_1;
            bool power_2;
            double num;
            bool is_equastion;
            RealVariable(double co1,bool pow1,double co2,bool pow2,char x,double num){
                var = x;
                cofficcient_1 = co1;
                power_1 = pow1;
                this->num = num;
                power_2 = pow2;
                cofficcient_2 = co2;
                is_equastion = false;
            }
            RealVariable(){
                cofficcient_1 = 1;
                var = 'x';
                num = 0;
                power_1 = true;
                power_2 = false;
                cofficcient_2 = 0;
                is_equastion = false;
            }

        friend RealVariable operator +(const RealVariable& x, const RealVariable& y);
        friend RealVariable operator +(const RealVariable& x, const double y);
        friend RealVariable operator +(const double x, const RealVariable& y);
        friend RealVariable operator -(const RealVariable& x, const RealVariable& y);
        friend RealVariable operator -(const RealVariable& x, const double y);
        friend RealVariable operator -(const double x, const RealVariable& y);
        friend RealVariable operator *(const RealVariable& x, const RealVariable& y);
        friend RealVariable operator *(const RealVariable& x, const double y);
        friend RealVariable operator *(const double x, const RealVariable& y);
        friend RealVariable operator /(const RealVariable& x, const RealVariable& y);
        friend RealVariable operator /(const RealVariable& x, const double y);
        friend RealVariable operator /(const double x, const RealVariable& y);
        friend RealVariable operator ^(const RealVariable& x, const RealVariable& y);
        friend RealVariable operator ^(const RealVariable& x, const double y);
        friend RealVariable operator ^(const double x, const RealVariable& y);
        friend RealVariable operator ==(const RealVariable& x, const RealVariable& y);
        friend RealVariable operator ==(const RealVariable& x, const double y);
        friend RealVariable operator ==(const double x, const RealVariable& y);
    };

    class ComplexVariable{
        public:
            std::complex<double> x_2;
            std::complex<double> x_1;
            std::complex<double> c;
            ComplexVariable(std::complex<double> x_2, std::complex<double> x_1, std::complex<double> c){
                this->x_2 = x_2;
                this->x_1 = x_1;
                this->c = c;
            }
            ComplexVariable(){
                x_2 = 0;
                x_1 = 1;
                c = 0;
            }

            friend ComplexVariable operator +(const ComplexVariable& c1, const ComplexVariable& c2);
            friend ComplexVariable operator +(const ComplexVariable& c, const double x);
            friend ComplexVariable operator +(const double x, const ComplexVariable& c);
            friend ComplexVariable operator +(const ComplexVariable& c1, std::complex<double> c2);
            friend ComplexVariable operator +(std::complex<double> c2, const ComplexVariable& c1);
            friend ComplexVariable operator -(const ComplexVariable& c1, const ComplexVariable& c2);
            friend ComplexVariable operator -(const ComplexVariable& c, const double x);
            friend ComplexVariable operator -(const double x, const ComplexVariable& c);
            friend ComplexVariable operator -(const ComplexVariable& c1, std::complex<double> c2);
            friend ComplexVariable operator -(std::complex<double> c2, const ComplexVariable& c1);
            friend ComplexVariable operator *(const ComplexVariable& c1, const ComplexVariable& c2);
            friend ComplexVariable operator *(const ComplexVariable& c, const double x);
            friend ComplexVariable operator *(const double x, const ComplexVariable& c);
            friend ComplexVariable operator *(const ComplexVariable& c1, std::complex<double> c2);
            friend ComplexVariable operator *(std::complex<double> c2, const ComplexVariable& c1);
            friend ComplexVariable operator /(const ComplexVariable& c1, const ComplexVariable& c2);
            friend ComplexVariable operator /(const ComplexVariable& c, const double x);
            friend ComplexVariable operator /(const double x, const ComplexVariable& c);
            friend ComplexVariable operator /(const ComplexVariable& c1, std::complex<double> c2);
            friend ComplexVariable operator /(std::complex<double> c2, const ComplexVariable& c1);
            friend ComplexVariable operator ^(const ComplexVariable& c1, const ComplexVariable& c2);
            friend ComplexVariable operator ^(const ComplexVariable& c, const double x);
            friend ComplexVariable operator ^(const double x, const ComplexVariable& c);
            friend ComplexVariable operator ^(const ComplexVariable& c1, std::complex<double> c2);
            friend ComplexVariable operator ==(const ComplexVariable& c1, const ComplexVariable& c2);
            friend ComplexVariable operator ==(const ComplexVariable& c, const double x);
            friend ComplexVariable operator ==(const double x, const ComplexVariable& c);
            friend ComplexVariable operator ==(const ComplexVariable& c1, std::complex<double> c2);
            friend ComplexVariable operator ==(std::complex<double> c2, const ComplexVariable& c1);
    };

    double solve(RealVariable);//Function has to clear the varables of the reference
    std::complex<double> solve(ComplexVariable);

}