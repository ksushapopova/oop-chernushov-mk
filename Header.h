#pragma once
class BigString {
private:
	unsigned long p1;
	unsigned long p2;
public:
	BigString(unsigned long, unsigned long);
	BigString()
	{
		/*unsigned long */
		p1 = 0;
		/*unsigned long */
		p2 = 0;
	}
	 
	void setp1(unsigned long part1);

	void setp2(unsigned long part1);

	int getp1();

	int getp2();
	std::string To_Str(/*unsigned long p1, unsigned long p2*/);

	BigString operator &(const BigString& t) const; // and
	BigString operator |(const BigString& t) const; // or
	BigString operator ^(const BigString& t) const; // xor
	BigString operator -() const; // not
	BigString operator <<(int n) const; // shiftLeft
	BigString operator >>(int n) const; // shiftRight
	//void print() const; // вывод битов

	//string toString();

	//void setBigString(double dAngle);
	//int getBigString();
};