#include "../include/Personal.h"

Personal::Personal(int id, std::string name,
                   int work_time, Positions position, int payment) : Employee(id, name, work_time, position, payment) {
                    salary = 0;
                   }

void Personal::print_info() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Work time: " << work_time << std::endl;
    std::cout << "Position: " << enum_print[position] << std::endl;
    std::cout << "Payment: " << payment << std::endl;
    std::cout << "Salary: " << salary << std::endl;
    std::cout << std::endl;
}

int Personal::calc_base_salary(int payment, int work_time) {
    int base_salary = payment * work_time;
    return base_salary;
}

int Personal::calc_bonus_salary(int bonus) {
    return bonus;
}

Driver::Driver(int id, std::string name,
               int work_time, Positions position, int payment): 
               Personal(id, name, work_time, position, payment) {}

int Driver::calc_salary() {
    salary = calc_base_salary(payment, work_time) + calc_bonus_salary(5);
    return salary;
}

int Driver::calc_bonus_salary(int hours) {
    return hours * 500;
}

Cleaner::Cleaner(int id, std::string name,
            int work_time, Positions position, int payment):
            Personal(id, name, work_time, position, payment) {}

int Cleaner::calc_salary() {
    salary = calc_base_salary(payment, work_time);
    return salary;
}