#include "../include/Project.h"

Project::Project(int id, int budget, int num_of_workers) {
    this->id = id;
    this->budget = budget;
    this->num_of_workers = num_of_workers;
}

int Project::get_id() {
    return id;
}

int Project::get_budget() {
    return budget;
}
int Project::get_workers() {
    return num_of_workers;
}
int Project::get_programmers() {
    return num_of_programmers;
}

void Project::plus_programmer() {
    num_of_programmers++;
}
ProjectManager::ProjectManager(int id, std::string name, int work_time, int payment, Positions position,
                                std::vector<Project*> project): Employee(id, name, 
                                work_time, position, payment) {
                                        this->project = project;
                                }
int ProjectManager::calc_budget_part() {
    int budget_part = 0;
    for (int i = 0; i < project.size(); i++) {
        budget_part += (int)(project[i]->get_budget()/project[i]->get_workers());
    }
    return budget_part;
}

int ProjectManager::calc_Heads() {
    int calc = 0;
    for (int i = 0; i < project.size(); i++) {
        calc += (project[i]->get_workers()-1)*75;
    }
    return calc;
}

int ProjectManager::calc_salary() {
    return calc_budget_part() + calc_Heads();
}
void ProjectManager::print_projects() {
    for(int i = 0; i < project.size(); i++) {
        std::cout << project[i]->get_id() << " ";
    }
    std::cout << std::endl;
}
void ProjectManager::print_info() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Position: " << enum_print[position] << std::endl;
    std::cout << "Projects: ";
    print_projects();
    std::cout << "Salary: " << calc_salary() << std::endl;
    std::cout << std::endl;
}
SeniorManager::SeniorManager(int id, std::string& name, int work_time, int payment, Positions position,
                              std::vector<Project*> projects): ProjectManager(id, name, work_time, payment, position,
                              projects) {}