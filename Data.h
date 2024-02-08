#pragma once
const int DEFAULT_DATE_DAY = 1;
const int DEFAULT_DATE_MONTH = 1;
const int DEFAULT_DATE_YEAR = 0;
const int DAYS_IN_YEAR_WITHOUT_FEB = 337;

class Date {

    //int d = DEFAULT_DATE_DAY, m = DEFAULT_DATE_MONTH, y = DEFAULT_DATE_YEAR;
    int d, m, y;
    int GetDaysInFeb(int year)const;
    int GetDaysInMonth(int month, int year)const;
    int GetDaysInYear(int year) const;
    bool IsCorrectDate();
    int DaysPassedToMonth(int month, int year)const;
    int GetDays() const;

    friend std::ostream& operator << (std::ostream& out, const Date& other);
    friend std::istream& operator >> (std::istream& in, Date& other);
public:

    Date();
    Date(int year, int month, int day);
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;
    void SetFromDays(int inp_days);
    Date operator + (int k);
    Date operator - (int k);
    int operator - (const Date& other);

};