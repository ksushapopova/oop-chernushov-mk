#include <iostream>
#include "Complex.h"
#include "Money.h"
#include <sstream>

int main()
{
    Pair* x = new Complex(3, -4);
    Pair* y = new Complex(2, 5);
    //Pair* z1 = *x + y;
    Complex* res1 = dynamic_cast<Complex*>(x);
    std::cout << *res1<< std::endl;
    Pair* z2 = *res1 * y;
    Complex* res2 = dynamic_cast<Complex*>(z2);
    std::cout << *res2 << std::endl;

    Pair* pmoney_1 = new Money(1000, 0.70);
    Pair* pmoney_2 = new Money(50, 0.80);    Pair* pmoney_3 = *pmoney_1 + pmoney_2;
    Money* pmoneymoney_1 = dynamic_cast<Money*>(pmoney_3);
    std::cout << *pmoneymoney_1;
    Pair* pmoney_4 = *pmoney_1 - pmoney_2;
    Money* pmoneymoney_2 = dynamic_cast<Money*>(pmoney_4);
    std::cout << *pmoneymoney_2;
    Pair* res3 = *pmoneymoney_1 * 4;
    Money* result3 = dynamic_cast<Money*>(res3);
    std::cout << *result3;
    Pair* res4 = *result3 /4;
    Money* result4 = dynamic_cast<Money*>(res4);
    std::cout << *result4;
}