#include <iostream>
#include <string>
#include "Data.h"
#include "Salary.h"

Payment::Payment(std::string name, double base_salary, Date year, double bonus_percent, int work_days, int total_day)
{
    full_name = name;
    salary = base_salary;
    start_year = year;
    bonus_percentage = bonus_percent;
    worked_days = work_days;
    total_days = total_day;
}

double Payment::calculateEarnings()//начисленная
{
    double earnings = ((salary * worked_days) / total_days);
    double bonus = earnings * (bonus_percentage / 100);
    double total_earnings = earnings + bonus;
    return total_earnings;
}

double Payment::calculateWithholdings(double total_earnings)//удержанная сумма
{
    double pension_contribution = total_earnings * 0.01;
    double income_tax = (total_earnings - pension_contribution) * (income_tax_percentage / 100);
    double total_withholdings = pension_contribution + income_tax;
    return total_withholdings;
}

double Payment::calculateTakeHomePay(double total_earnings, double total_withholdings)//выдданная
{
    return total_earnings - total_withholdings;
}

Date Payment::calculateExperience()//стаж
{
    Date today = Date(2023, 11, 20);
    Date experience;
    experience.SetFromDays(today - start_year);
    return experience;
}
