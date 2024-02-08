#include <iostream> 
#include "Data.h" 

int Date::GetDaysInFeb(int year) const
{
    if ((!(year % 4) && (year % 100)) || !(year % 400)) 
    {
        return 29;
    }
        return 28;
}

int Date::GetDaysInMonth(int month, int year) const  {
    switch (month) 
    {
    case 2:
        return GetDaysInFeb(year);
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    default:
        return 30;
    }
}

int Date:: GetDaysInYear(int year) const
{
    return DAYS_IN_YEAR_WITHOUT_FEB + GetDaysInFeb(year);
}

bool Date::IsCorrectDate()
{
    return GetMonth() <= 12 && GetMonth() >= 1 && GetDay() <= GetDaysInMonth(GetMonth(), GetYear()) && GetDay() > 0;
}

int Date::DaysPassedToMonth(int month, int year) const
{
    int days = 0;
    for (int i = 1; i < month; ++i) 
    {
        days += GetDaysInMonth(i, year);
    }
    return days;
}

int Date::GetDays() const
{
    int days = 0;
    for (int i = DEFAULT_DATE_YEAR; i < GetYear(); ++i) 
    {
        days += GetDaysInYear(i);
    }
    return days + DaysPassedToMonth(GetMonth(), GetYear()) + GetDay();
}

void Date::SetFromDays(int inp_days) 
{
    m = DEFAULT_DATE_MONTH;
    y = DEFAULT_DATE_YEAR;

    while (inp_days > GetDaysInYear(GetYear())) 
    { 
        inp_days -= GetDaysInYear(GetYear());
        ++y;
    }

    while (inp_days > DaysPassedToMonth(GetMonth() + 1, GetYear())) 
    {
        ++m;
    }

    d = inp_days - DaysPassedToMonth(GetMonth(), GetYear()); 
}

Date::Date() : y{ DEFAULT_DATE_YEAR }, m{ DEFAULT_DATE_MONTH }, d{ DEFAULT_DATE_DAY }{}

Date::Date(int year, int month, int day):  y{ year}, m{ month }, d{ day }{}

int Date::GetDay() const 
{
    return d;
}

int Date::GetMonth() const 
{
    return m;
}

int Date::GetYear() const 
{
    return y;
}

Date Date::operator + (int k)
{
    Date result(*this);
    result.SetFromDays(result.GetDays() + k);
    return result;
}

Date Date::operator - (int k)
{
    Date result(*this);
    result.SetFromDays(result.GetDays() - k);
    return result;
}

int Date::operator - (const Date& other) 
{
    return GetDays() - other.GetDays();
}

std::ostream& operator<<(std::ostream& out, const Date& other) {
    out << '(' << other.y << ',' << other.m << ',' << other.d << ')'; return out;
}
std::istream& operator>>(std::istream& in, Date& other){
    in >> other.y >> other.m >> other.d; return in; 
}
