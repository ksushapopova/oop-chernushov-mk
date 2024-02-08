#include <iostream> 
#include "Angle.h"
#include <string>
using namespace std;

void Angle::normilize() 
{
    if ((*mint) < 0)
    {
        (*mint) *= -1;
    }
    while ((*deg) < 0)
    {
        (*deg) += 360;
    }
    while ((*mint) >= 60)
    {
        (*mint) -= 60;
        (*deg) += 1;
    }
    while ((*deg) >360)
    {
        (*deg) -= 360;
    }
}
Angle::~Angle()
{
    delete deg;
    delete mint; 
}
Angle::Angle() : deg(new int(0)), mint(new int(0)) {}

Angle::Angle(const int& deg = 0, const int& mint = 0)
    : deg(new int(deg)), mint(new int(mint)) {normilize();}

Angle::Angle(const Angle& other)
{
    deg = new int;
    *deg = *other.deg;
    mint = new int;
    *mint = *other.mint;
}

double Angle::toRad()
{
    return (*deg) * pi / 180;
}

double Angle::sinn()
{
    return sin(((*deg) + (*mint) / 60) * pi / 180);
}

Angle& Angle::operator=(const Angle& other) {
    *deg = *other.deg; *mint = *other.mint;
    return *this;
}
Angle& Angle::operator+=(const Angle& other) {
    *deg = *deg + *other.deg;
    *mint = *mint + *other.mint; 
    normilize(); return *this;
}
Angle Angle::operator+(const Angle& other) {
    return Angle(*deg + *other.deg, *mint + *other.mint);
}
Angle& Angle::operator-=(const Angle& other)
{
    *deg = *deg - *other.deg;
    *mint = *mint - *other.mint;
    normilize(); return *this;
}
Angle Angle::operator-(const Angle& other) {
    return Angle(*deg - *other.deg, *mint - *other.mint);
}
Angle& Angle::operator*=(const Angle& other) {
    *deg = (*deg) * (*other.deg); *mint = (*mint) * (*other.mint);
    normilize(); return *this;
}
Angle Angle::operator*(const Angle& other)
{
    return Angle((*deg) * (*other.deg), (*mint) * (*other.mint));
}

Angle& Angle::operator/=(const Angle& other)
{
    *deg = (*deg) / (*other.deg); *mint = (*mint) / (*other.mint);
    normilize(); return *this;
}
Angle Angle::operator/(const Angle& other)
{
    return Angle((*deg) / (*other.deg), (*mint) / (*other.mint));
}
std::ostream& operator<<(std::ostream& out, const Angle& other) {
    out << '(' << *other.deg << ',' << *other.mint << ')'; return out;
}
std::istream& operator>>(std::istream& in, Angle& other) {
    in >> *other.deg >> *other.mint; return in;
}

std::string Angle::toStr()
{
    std::string str;
    str = to_string(*deg) + " " + to_string(*mint) + "'" + "\n";
    return str;
}