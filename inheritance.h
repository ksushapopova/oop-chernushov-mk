#pragma once

#include <iostream> 

class Pair
{
	friend std::ostream& operator<< (std::ostream& out, const Pair& other);
protected:
	double left;
	double right;
public:
	Pair();
	Pair(double Left, double Right);
	Pair(const Pair& obj) { left = obj.left; right = obj.right; }
	double getLeft() const;
	double getRight() const;
	Pair operator+(const Pair& other);
	Pair operator-(const Pair& other);
};

class Complex :
	public Pair
{
	friend std::ostream& operator<< (std::ostream& out, const Complex& other);
public:
	Complex();
	Complex(double Left, double Right);
	Complex conjurate() const;
	Complex operator+(const Complex& other);
	Complex operator-(const Complex& other);
	Complex operator* (const Complex& other);
	Complex operator/ (const Complex& other);
};