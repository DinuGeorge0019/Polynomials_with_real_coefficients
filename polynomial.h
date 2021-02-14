#pragma once
#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Polynomial
{
private:
    unsigned degree;
    vector<double> coeffs;

public:
    Polynomial(int deg);
    Polynomial(unsigned deg, initializer_list<double> cs);
    Polynomial(initializer_list<double> cs);
    Polynomial(vector<double> cs);


    friend ostream& operator << (ostream& os, const Polynomial& poli);
    friend Polynomial operator + (const Polynomial& p1, const Polynomial& p2);
    friend Polynomial operator - (const Polynomial& p1, const Polynomial& p2);
    friend Polynomial operator * (const Polynomial& p1, const Polynomial& p2);
    friend Polynomial operator / (const Polynomial& p1, const Polynomial& p2); //NOT USED
    Polynomial operator ^ (const int& power);
    double operator () (const double& x);
    double operator [] (const int& x);
    Polynomial truncate();
};

double evaluate_expresion_v1(Polynomial p1, Polynomial p2, Polynomial p3, double x);
double evaluate_expresion_v2(Polynomial p1, Polynomial p2, Polynomial p3, double x);