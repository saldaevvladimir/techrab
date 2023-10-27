#pragma once
#include <iostream>
#include <string>

const float EPS = 1e-5f;

struct Complex
{
public:
    Complex();
    Complex(float real);
    Complex(float real, float imag);

    float real();
    float imag();

    std::string to_string();

    void set_real(float real);
    void set_imag(float real);

    float abs();

    Complex pow(int exp);

    Complex operator+(Complex other);
    Complex operator-(Complex other);
    Complex operator*(Complex other);
    Complex operator*(float num);
    Complex operator/(Complex other);
    Complex operator/(float num);
    bool operator==(Complex other);
    bool operator!=(Complex other);

    friend std::ostream& operator<<(std::ostream& os, Complex obj);

private:
    float re, im;
};


bool are_eq(float num1, float num2);