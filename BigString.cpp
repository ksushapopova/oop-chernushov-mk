#include <iostream> 
#include "Header.h" 
#include <string>
using namespace std;

BigString::BigString(unsigned long part1, unsigned long part2)
{
    p1 = part1;
    p2 = part2;
}


void BigString::setp1(unsigned long part1)
{
    p1 = part1;
}
void BigString::setp2(unsigned long part1)
{
    p2 = part1;
}
int BigString::getp1()
{
    return p1;
}
int BigString::getp2()
{
    return p2;
}

std::string BigString::To_Str(/*unsigned long p1, unsigned long p2*/)
{
    string str;
    str = to_string(p1) + to_string(p2);
    return str;
}

BigString BigString::operator &(const BigString& t) const
{
    return BigString(p1 & t.p1, p2 & t.p2);
}
BigString BigString::operator|(const BigString& t) const {
    return BigString(p1 | t.p1, p2 | t.p2);
}
BigString BigString::operator^(const BigString& t) const {
    return BigString(p1 ^ t.p1, p2 ^ t.p2);
}
BigString BigString::operator-() const
{
    return BigString(~p1, ~p2);
}
BigString BigString::operator<<(int n) const {
    if (n >= 64) {
        return BigString(0, 0);
    }
    else if (n == 0) {
        return *this;
    }
    else if (n >= 32) {
        return BigString(p2 << (n - 32), 0);
    }
    else {
        return BigString((p1 << n) | (p2 >> (32 - n)), p2 << n);
    }
}

BigString BigString::operator>>(int n) const {
    if (n >= 64) {
        return BigString(0, 0);
    }
    else if (n == 0) {
        return *this;
    }
    else if (n >= 32) {
        return BigString(0, p1 >> (n - 32));
    }
    else {
        return BigString(p1 >> n, (p1 << (32 - n)) | (p2 >> n));
    }
}
