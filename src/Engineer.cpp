#include "../include/Engineer.h"
#include "../include/Project.h"
Engineer::Engineer( int id, std::string name,
              int work_time,  int payment, Positions position)
    : Personal(id, name, work_time, position, payment) {}

int Engineer::calc_salary() {
    return calc_base_salary(payment, work_time) + calc_budget_part();
}

int Engineer::calc_budget_part() {
    return (int)project->get_budget()/project->get_workers();
}
void Engineer::print_info() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Work time: " << work_time << std::endl;
    std::cout << "Payment: " << payment << std::endl;
    std::cout << "Position: " << enum_print[position] << std::endl;
    std::cout << "Project: " << project->get_id() << std::endl;
    std::cout << "Salary: " << salary << std::endl;
    std::cout << std::endl;
}   
Tester::Tester(int id, std::string name, Positions position, int work_time, int payment, Project* project, int bugs):
               Engineer(id, name, work_time, payment, position) {
                this->project = project;
                this->bugs = bugs;
}

int Tester::calc_pro_additions(int bonus) {
    return 500*bonus;
}

int Tester::calc_salary() {
    salary = calc_base_salary(payment, work_time) + calc_budget_part() + calc_pro_additions(bugs);
    return salary;
}

void Tester::set_bugs(int bugs) {
    this->bugs = bugs;
}

Programmer::Programmer(int id, std::string name, Positions position, int work_time, int payment, Project* project):
                        Engineer(id, name, work_time, payment, position){
                         this->project = project;
                        }

int Programmer::calc_pro_additions(int bonus) {
    if (work_time < 10) {
        return bonus;
    }
    return 0;
}

int Programmer::calc_salary() {
    salary = calc_base_salary(payment, work_time) + calc_budget_part() + calc_pro_additions(5000);
    return salary;
}

TeamLeader::TeamLeader(int id, std::string name, Positions position, int worktime,
                        int payment, Project* project):
                        Programmer(id, name, position, work_time, payment, project) {}

int TeamLeader::calc_Heads() {
    return project->get_programmers()*100;
}

int TeamLeader::calc_salary() {
    salary = calc_base_salary(payment, work_time) + calc_Heads() + calc_budget_part();
    return salary;
}