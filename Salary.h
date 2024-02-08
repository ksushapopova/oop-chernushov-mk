#include <iostream>
#include <string>
#include "Data.h"

class Payment {
private:
    std::string full_name;
    double salary;
    Date start_year;
    double bonus_percentage;//������� ��������
    double income_tax_percentage = 13;//���������� �����
    int worked_days;
    int total_days;

public:
    Payment(std::string name, double base_salary, Date year, double bonus_percent, int work_days, int total_day);
    double calculateEarnings();
    double calculateWithholdings(double total_earnings);
    double calculateTakeHomePay(double total_earnings, double total_withholdings);
    Date calculateExperience();
};
