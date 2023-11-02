#include "../lib/complex/headers/Complex.h"
#include <gtest/gtest.h>


TEST (ComplexTests, DefaultConstructorTest)
{
    Complex num;

    bool correct_num = (are_eq(num.real(), 0.0) && are_eq(num.imag(), 0.0));

    ASSERT_TRUE(correct_num); 
}

TEST (ComplexTests, ParameterConstructor1Test)
{
    Complex num(3.14f);

    bool correct_num = (are_eq(num.real(), 3.14f) && are_eq(num.imag(), 0.0));

    ASSERT_TRUE(correct_num);
}

TEST (ComplexTests, ParameterConstructor2Test)
{
    Complex num(3.14, 3.14);

    bool correct_num = (are_eq(num.real(), 3.14) && are_eq(num.imag(), 3.14));

    ASSERT_TRUE(correct_num);
}

TEST (ComplexTests, GetRealTest)
{
    Complex num(3.14);

    bool correct_real = are_eq(num.real(), 3.14);

    ASSERT_TRUE(correct_real);
}

TEST (ComplexTests, GetImagTest)
{
    Complex num(3.14, 3.15);

    bool correct_imag = are_eq(num.imag(), 3.15);

    ASSERT_TRUE(correct_imag);
}

TEST (ComplexTests, SetRealTest)
{
    Complex num;

    num.set_real(3.14);

    bool correct_real = are_eq(num.real(), 3.14);

    ASSERT_TRUE(correct_real);
}

TEST (ComplexTests, SetImagTest)
{
    Complex num;

    num.set_imag(3.14);

    bool correct_imag = are_eq(num.imag(), 3.14);

    ASSERT_TRUE(correct_imag);
}

TEST (ComplexTests, ToStringTest)
{
    Complex num(3, 4);

    bool correct_str = num.to_string() == "3.000000+4.000000i";

    ASSERT_TRUE(correct_str);
}

TEST (ComplexTests, ABSTest)
{
    Complex num(3, 4);

    bool correct_abs = are_eq(num.abs(), 5);

    ASSERT_TRUE(correct_abs);
}

TEST (ComplexTests, PowTest)
{
    Complex num(3, 4);
    int exp = 3;

    bool correct_pow = num.pow(exp) == Complex(-117, 44);

    ASSERT_TRUE(correct_pow);
}

TEST (ComplexTests, SumTest)
{
    bool correct_sum = Complex(1, 2) + Complex(3, 4) == Complex(4, 6);

    ASSERT_TRUE(correct_sum);
}

TEST (ComplexTests, SubTest)
{
    bool correct_sub = Complex(4, 6) - Complex(3, 4) == Complex(1, 2);

    ASSERT_TRUE(correct_sub);
}

TEST (ComplexTests, MulTest)
{
    bool correct_mul = Complex(1, 2) * Complex(3, 4) == Complex(-5, 10);

    ASSERT_TRUE(correct_mul);
}

TEST (ComplexTests, DivTest)
{
    bool correct_div = Complex(1, 2) / Complex(3, 4) == Complex(0.44, 0.08);

    ASSERT_TRUE(correct_div);
}

TEST (ComplexTests, EqTest)
{
    bool correct_eq = Complex(1, 2) == Complex(1, 2);

    ASSERT_TRUE(correct_eq);
}

TEST (ComplexTests, NeTest)
{
    bool correct_ne = Complex(1, 2) != Complex(3, 4);

    ASSERT_TRUE(correct_ne);
}


