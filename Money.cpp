#include <iostream>
#include "Money.h"

Money::Money() :Pair()
{}

Money::Money(double r, double p) :Pair(r, p)
{}

Pair* Money::operator +(Pair* other)
{
	double r, p, summ = left + other->getLeft() + right + other->getRight();
	r = floor(summ);
	p = summ - r;
	Pair* pmoney = new Money(r, p);
	return pmoney;
}

Pair* Money::operator -(Pair* other)
{
	double r, p, dif = abs(left + right - other->getLeft() - other->getRight());
	r = floor(dif);
	p = dif - r;
	Pair* pmoney = new Money(r, p);
	return pmoney;
}

Pair* Money::operator *(double a)
{
	double r, p, mul = a*(left+right);
	r = floor(mul);
	p = mul - r;
	Pair* pmoney = new Money(r, p);
	return pmoney;
}


Pair* Money::operator /(double a)
{
	double r, p, mul = (left + right)/a;
	r = floor(mul);
	p = mul - r;
	Pair* pmoney = new Money(r, p);
	return pmoney;
}

std::ostream& operator <<(std::ostream& out, Money& money)
{
	out << money.getLeft() + ',' + money.getRight() << '\n';
	return out;
}