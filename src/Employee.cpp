#include "../include/Employee.h"

Employee::Employee(int id, std::string name,
             int work_time, Positions position, int payment){
                this->id = id;
                this->name = name;
                this->work_time = work_time;
                this->position = position;
                this->payment = payment;
             }

void Employee::set_work_time(int hours) {
    work_time = hours;
}