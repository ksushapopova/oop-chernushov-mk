#pragma once

#include <iostream> 
#include <string>

class Angle
{

	int* deg;
	int* mint;
	const double pi = 3.1415926535;
	void normilize();
	friend std::ostream& operator << (std::ostream& out, const Angle& other);
	friend std::istream& operator >> (std::istream& in, Angle& other);
public:
	Angle();
	~Angle();
	Angle(const int& deg, const int& mint);
	Angle(const Angle& other);
	double toRad();
	double sinn();
	Angle& operator = (const Angle& other);
	Angle& operator += (const Angle& other);
	Angle operator + (const Angle& other);
	Angle& operator -= (const Angle& other);
	Angle operator - (const Angle& other);
	Angle& operator *= (const Angle& other);
	Angle operator * (const Angle& other);
	Angle& operator /= (const Angle& other);
	Angle operator / (const Angle& other);
	std::string toStr();
};