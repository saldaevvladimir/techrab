#pragma once
#include <iostream>
#include <string>

constexpr double EPS = 1e-10;

struct Complex
{
public:
    Complex(double real = 0.0, double imag = 0.0);

    double real() const;
    double imag() const;

    std::string to_string() const;

    void set_real(double real);
    void set_imag(double real);

    double abs() const;

    Complex pow(int exp) const;

    Complex operator+(Complex other) const;
    Complex operator-(Complex other) const;
    Complex operator*(Complex other) const;
    Complex operator*(double num) const;
    Complex operator/(Complex other) const;
    Complex operator/(double num) const;
    bool operator==(Complex other) const;
    bool operator!=(Complex other) const;

    friend std::ostream& operator<<(std::ostream& os, Complex obj);

private:
    double re, im;
};


bool are_eq(double num1, double num2);