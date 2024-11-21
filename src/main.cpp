#include <iostream>
#include "../include/Project.h"
#include "../include/Factory.h"

int main() {
    // создание штата сотрудников на основе файла
    std::vector<Employee*> staff = Factory_Staff::make_staff();
    // расчет зарплаты
    for(Employee* emp: staff) {
        emp -> calc_salary();
    }
    // вывод данных о зарплате
    for(Employee* emp: staff) {
        emp -> print_info();
    }
}