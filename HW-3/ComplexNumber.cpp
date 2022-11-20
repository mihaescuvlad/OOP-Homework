#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double real, double imaginary) : m_real{real}, m_imaginary{imaginary}
{
}

double ComplexNumber::getReal() const
{
	return m_real;
}

double ComplexNumber::getImaginary() const
{
	return m_imaginary;
}

ComplexNumber ComplexNumber::getSum(const ComplexNumber& a)
{
	return { this->m_real + a.getReal(), this->m_imaginary + a.getImaginary() };
}

ComplexNumber ComplexNumber::getProduct(const ComplexNumber& a)
{
	return { this->m_real * a.getReal() - this->m_imaginary * a.getImaginary() , (this->m_real + this->m_imaginary) * (a.getReal() + a.getImaginary())};
}