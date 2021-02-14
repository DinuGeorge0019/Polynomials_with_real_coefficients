#include "polynomial.h"


Polynomial::Polynomial(vector<double> cs) : degree(cs.size() == 0 ? 0 : cs.size() - 1), coeffs(cs)
{
    if (coeffs.size() == 0)
        coeffs.resize(1);
}

Polynomial::Polynomial(initializer_list<double> cs) : degree(cs.size() - 1), coeffs(cs) {};

Polynomial::Polynomial(unsigned deg, initializer_list<double> cs) : degree(deg), coeffs(deg + 1)
{

    for (auto it = cs.begin(); it != cs.end(); ++it)
        coeffs[it - cs.begin()] = *it;
}

Polynomial::Polynomial(int deg) : degree(deg), coeffs(deg + 1) {}

ostream& operator << (ostream& os, const Polynomial& p)
{

    if (p.degree == 0)
    {
        os << p.coeffs[0];
        return os;
    }


    for (size_t i = 0; i < p.degree - 1; i++)
    {
        if (p.coeffs[i] != 0)
        {
            os << p.coeffs[i] << "x^" << p.degree - i << " + ";
        }
    }


    os << p.coeffs[p.degree - 1] << "x + " << p.coeffs[p.degree];

    return os;
}

Polynomial operator + (const Polynomial& p1, const Polynomial& p2)
{
    if (p1.degree < p2.degree)
    {
        return p2 + p1;
    }

    Polynomial temp_p = p1;

    for (size_t i = 0; i <= p2.degree; i++)
    {
        temp_p.coeffs[temp_p.degree - p2.degree + i] += p2.coeffs[i];
    }

    return temp_p;
}

Polynomial operator * (const Polynomial& p1, const Polynomial& p2)
{
    Polynomial prod(p1.degree + p2.degree);

    for (size_t i = 0; i <= p1.degree; ++i)
        for (size_t j = 0; j <= p2.degree; ++j)
            prod.coeffs[i + j] += p1.coeffs[i] * p2.coeffs[j];

    return prod;
}

Polynomial operator - (const Polynomial& p1, const Polynomial& p2)
{
	Polynomial inverse_p2 = Polynomial{ -1 } *p2;
	return inverse_p2 + p1;
}


Polynomial Polynomial::truncate()
{

    if (coeffs[0] != 0 || coeffs.size() == 1)
        return *this;
    else
    {
        vector<double> temp(coeffs.begin() + 1, coeffs.end());
        return *this = Polynomial(temp).truncate();
    }
}

Polynomial operator / (const Polynomial& p1, const Polynomial& p2)
{

    if (p1.degree < p2.degree)
    {
        cout << " The whole part :" << 0;
        cout << " The fractional part : " << p1.degree;
        return Polynomial(0);
    }

    Polynomial quotient(p1.degree - p2.degree);
    Polynomial remainder(p1);

    while (remainder.truncate().degree >= p2.degree)
    {
        Polynomial multiplier(remainder.degree - p2.degree, { remainder.coeffs[0] / p2.coeffs[0] });

        remainder = remainder - (multiplier * p2);
        quotient = quotient + multiplier;

        if (multiplier.coeffs[0] == 0 && multiplier.degree == 0)
            break;

    }

    cout << " The whole part :" << quotient;
    cout << " The fractional part : : " << remainder;
    return quotient;


}

Polynomial Polynomial::operator ^ (const int& power)
{
    if (power == 0)
    {
        *this = Polynomial{ 1 };
        return *this;
    }

    Polynomial temp = *this;

    for (int i = 1; i < power; i++)
    {
        *this = *this * temp;
    }

    return *this;

}

double Polynomial::operator () (const double& x)
{
    double total = 0;

    for (int i = degree; i >= 0; i--)
    {
        total += coeffs[degree - i] * pow(x, i);
    }

    return total;
}

double Polynomial::operator [] (const int& x)
{
    if (x > degree)
    {
        cout << "Out of range" << endl;
        return -1;
    }

    return coeffs[degree - x];
}

double evaluate_expresion_v1(Polynomial p1, Polynomial p2, Polynomial p3, double x)
{
    double v1 = (p1 ^ 2)(x) - (p2(x) * p3(x));
    cout << "V1 = " << v1 << endl;
    return v1;

}

double evaluate_expresion_v2(Polynomial p1, Polynomial p2, Polynomial p3, double x)
{
    double v2 = ((p1 ^ 2) - (p2 * p3))(x);
    cout << "V2 = " << v2 << endl;
    return v2;
}