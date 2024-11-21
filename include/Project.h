#ifndef INCLUDE_PROJECT_H_
#define INCLUDE_PROJECT_H_
#include <iostream>
#include "Interfaces.h"
#include "Employee.h"
class Project {
    public:
        Project(int id, int budget, int num_of_workers);
        Project() = default;
        int get_budget();
        int get_id();
        int get_workers();
        void plus_programmer();
        int get_programmers();
    private:
        int id;
        int budget;
        int num_of_workers;
        int num_of_programmers = 0;
};

class ProjectManager : public Project, public Employee, public Project_Budget, public Heading, public Work_Base_Time {
    public:
        ProjectManager(int id, std::string name, int worktime, int payment, Positions position, std::vector<Project*> projects);
        int calc_budget_part() override;
        int calc_Heads() override;
        int calc_salary() override;
        void print_info() override;
        void print_projects();
    private:
        std::vector<Project*> project;
};

class SeniorManager : public ProjectManager {
 public:
   SeniorManager(int id, std::string& name, int workTime, int payment, Positions position,  std::vector<Project*> projects);
 private:
   std::vector<Project*> projects;
};

#endif  // INCLUDE_PROJECT_H_