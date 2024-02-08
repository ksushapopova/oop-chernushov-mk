#pragma once
#include <iostream> 

class Pair
{
protected:
	double left;
	double right;
public:
	Pair() : left(0), right(0) {}
	Pair(double Left, double Rigth): left(Left), right(Rigth) {};
	double getLeft()
	{
		return left;
	}
	double getRight()
	{
		return right;
	}
	void SetLeft(double l)
	{
		left = l;
	}
	void SetRight(double r)
	{
		right = r;
	}
	virtual Pair* operator+(Pair* other) = 0;
	virtual Pair* operator-(Pair* other) = 0;
};

