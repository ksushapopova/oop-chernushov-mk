#include "Complex.h"
#include <sstream>


std::ostream& operator<<(std::ostream& out, Complex& other)
{
    out << '(' << other.left << " + " << other.right << 'i' << ')';
    return out;
}


Pair* Complex::conjurate() const 
{
	Pair* pcomplex_number = new Complex(left, (-1) * right);
	return pcomplex_number;
}

Pair* Complex::operator +(Pair* other)
{
    Pair* pcomplex_number = new Complex(left + other->getLeft(), right + other->getRight());
    return pcomplex_number;
}

Pair* Complex::operator -(Pair* other)
{
    Pair* pcomplex_number = new Complex(left - other->getLeft(), right - other->getRight());
    return pcomplex_number;
}

Pair* Complex::operator *(Pair* other)
{

	Pair* pcomplex_number = new Complex(left * other->getLeft() - right * other->getRight(),
		left * other->getRight() + right * other->getLeft());
	return pcomplex_number;
}

Pair* Complex::operator /(Pair* other)
{
	Pair* pcomplex_number = new Complex(0, 0);
	if (other->getLeft() != 0 && other->getRight() != 0)
	{
		pcomplex_number->SetLeft((left * other->getLeft() + right * other->getRight())
			/ (other->getLeft() * other->getLeft() + other->getRight() * other->getRight()));
		pcomplex_number->SetRight((right * other->getLeft() - left * other->getRight())
			/ (other->getLeft() * other->getLeft() + other->getRight() * other->getRight()));
	}
	return pcomplex_number;
}


