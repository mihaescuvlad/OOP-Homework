#include "ComplexNumber.h"
#include <iostream>
#include <cmath>

ComplexNumber::ComplexNumber(long double real, long double imaginary) : m_real{ real }, m_imaginary{ imaginary }
{
}

ComplexNumber operator+(const ComplexNumber& complex_number1, const ComplexNumber& complex_number2)
{
	return ComplexNumber{ complex_number1.m_real + complex_number2.m_real, complex_number1.m_imaginary + complex_number2.m_imaginary };
}

ComplexNumber operator-(const ComplexNumber& complex_number1, const ComplexNumber& complex_number2)
{
	return ComplexNumber{ complex_number1.m_real - complex_number2.m_real, complex_number1.m_imaginary - complex_number2.m_imaginary };
}

ComplexNumber operator*(const ComplexNumber& complex_number1, const ComplexNumber& complex_number2)
{
	return ComplexNumber{ (complex_number1.m_real + complex_number2.m_real) - (complex_number1.m_imaginary + complex_number2.m_imaginary),
		                  (complex_number1.m_real + complex_number2.m_imaginary) + (complex_number1.m_imaginary + complex_number2.m_real) };
}

long double operator~(const ComplexNumber& complex_number)
{
	return sqrt(pow(complex_number.m_real, 2.0) + pow(complex_number.m_imaginary, 2.0));
}

// Has precision errors
ComplexNumber operator^(const ComplexNumber& complex_number, const int& power)
{
	long double r = ~complex_number;
	long double tetha = std::atan(complex_number.getImaginary() / complex_number.getReal());

	r = pow(r, power);
	tetha *= power;

	long double a = r * cos(tetha);
	long double b = r * sin(tetha);

	return { a, b };
}

bool operator<(const ComplexNumber& complex_number1, const ComplexNumber& complex_number2)
{
	return ~complex_number1 < ~complex_number2;
}

long double ComplexNumber::getReal() const
{
	return m_real;
}

long double ComplexNumber::getImaginary() const
{
	return m_imaginary;
}

void ComplexNumber::printNum() const
{
	std::cout << m_real << " + i*(" << m_imaginary << ")\n";
}

ComplexNumber ComplexNumber::getMin(const ComplexNumber& complex_number) const
{
	return ~(*this) < ~complex_number ? *this : complex_number;
}