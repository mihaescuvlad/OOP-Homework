#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

class ComplexNumber
{
private:
	long double m_real;
	long double m_imaginary;
public:
	ComplexNumber(long double real = 0.0, long double imaginary = 0.0);

	long double getReal() const;
	long double getImaginary() const;

	void printNum();

	friend ComplexNumber operator+(const ComplexNumber& complex_number1, const ComplexNumber& complex_number2);
	friend ComplexNumber operator-(const ComplexNumber& complex_number1, const ComplexNumber& complex_number2);
	friend ComplexNumber operator*(const ComplexNumber& complex_number1, const ComplexNumber& complex_number2);
	friend long double operator~(const ComplexNumber& complex_number);
	friend ComplexNumber operator^(const ComplexNumber& complex_number, const int& power);
	friend bool operator< (const ComplexNumber& complex_number1, const ComplexNumber& complex_number2);
};

#endif
