#include "../headers/Complex.h"
#include <cmath>
#include <exception>


Complex::Complex()
{
    this->re = 0.0f;
    this->im = 0.0f;
}

Complex::Complex(float real)
{
    this->re = real;
    this->im = 0.0f;
}

Complex::Complex(float real, float imag)
{
    this->re = real;
    this->im = imag;
}

float Complex::real()
{
    return this->re;
}

float Complex::imag()
{
    return this->im;
}

std::string Complex::to_string()
{
    return std::to_string(this->re) + "+" + std::to_string(this->im) + "i";
}

void Complex::set_real(float real)
{
    this->re = real;
}

void Complex::set_imag(float imag)
{
    this->im = imag;
}

float Complex::abs()
{
    return std::sqrt(std::pow(this->re, 2) + std::pow(this->im, 2));
}

Complex Complex::pow(int exp)
{
    float abs = this->abs();

    if (std::fabs(abs) < EPS)
        throw std::exception("zero division");

    float expphi = std::acos(this->re / abs) * exp;

    float cos_expphi = std::cos(expphi);
    float sin_expphi = std::sin(expphi);

    return Complex(cos_expphi, sin_expphi) * std::pow(abs, exp);
}

Complex Complex::operator+(Complex other)
{
    return Complex(this->re + other.re, this->im + other.im);
}

Complex Complex::operator-(Complex other)
{
    return Complex(this->re - other.re, this->im - other.im);
}

Complex Complex::operator*(Complex other)
{
    return Complex(this->re * other.re - this->im * other.im, this->re * other.im + this->im * other.re);
}

Complex Complex::operator*(float num)
{
    return Complex(this->re * num, this->im * num);
}

Complex Complex::operator/(Complex other)
{
    float div = std::pow(other.re, 2) + std::pow(other.im, 2);

    if (std::fabs(div) < EPS)
        throw std::exception("zero division (Complex(0, 0))");

    return Complex((this->re * other.re + this->im * other.im), (this->im * other.re - this->re * other.im)) / div;
}

Complex Complex::operator/(float num)
{
    if (std::fabs(num) < EPS)
        throw std::exception("zero division");

    return Complex(this->re / num, this->im / num);
}

bool Complex::operator==(Complex other)
{
    return are_eq(this->re, other.re) && are_eq(this->im, other.im);
}

bool Complex::operator!=(Complex other)
{
    return !are_eq(this->re, other.re) || !are_eq(this->im, other.im);
}

std::ostream &operator<<(std::ostream &os, Complex complex)
{
    os << complex.to_string();
    
    return os;
}


bool are_eq(float num1, float num2)
{
    return std::fabs(num1 - num2) <= EPS;
}