#pragma once
#include "Pair.h"

class Money : public Pair
{
	friend std::ostream& operator<< (std::ostream& out, Money& other);
public:
	Money();
	Money(double rubles, double pennies);
	Pair* operator +(Pair* other) override;
	Pair* operator -(Pair* other) override;
	Pair* operator *(double a);
	Pair* operator /(double a); 
};