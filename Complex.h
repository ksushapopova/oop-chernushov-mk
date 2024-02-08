#pragma once
#include "Pair.h"
#include <string>
//#include <sstream>

class Complex : public Pair
{
	friend std::ostream& operator<< (std::ostream& out, Complex& other);
public:
	Complex():Pair(){};
	Complex(double Left, double Right) : Pair(Left, Right) {};
	Pair* conjurate() const;
	Pair* operator+(Pair* other) override;
	Pair* operator-(Pair* other) override;
	Pair* operator* (Pair* other);
	Pair* operator/ (Pair* other);
};