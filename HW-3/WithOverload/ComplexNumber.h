#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

class ComplexNumber
{
private:
	double m_real, m_imaginary;
public:
	ComplexNumber(double real = 0.0, double imaginary = 0.0);

	double getReal() const;
	double getImaginary() const;

	ComplexNumber getSum(const ComplexNumber& a);
	ComplexNumber getProduct(const ComplexNumber& a);
};

#endif