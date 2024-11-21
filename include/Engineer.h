#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <iostream>
#include "Personal.h"
#include "Interfaces.h"

class Project;

class Engineer : public Personal, public Project_Budget {
    public:
        Engineer(int id, std::string name, int work_time, int payment, Positions position);
        int calc_salary() override;
        int calc_budget_part() override;
        void print_info() override;
    protected:
        Project* project;
};

class Tester : public Engineer {
    public:
        Tester(int id, std::string name, Positions position, int worktime, int payment, Project* project, int bugs);
        int calc_pro_additions(int bonus) override;
        int calc_salary() override;
        void set_bugs(int bugs);
    private:
        int bugs;
};

class Programmer : public Engineer {
    public:
        Programmer(int id, std::string name, Positions position, int worktime, int payment, Project* project);
        int calc_pro_additions(int bonus) override;
        int calc_salary() override;
};

class TeamLeader : public Programmer, public Heading {
    public:
        TeamLeader(int id, std::string name, Positions position, int worktime, int payment, Project* project);
        int calc_Heads() override;
        int calc_salary() override;
};
#endif  // INCLUDE_ENGINEER_H_
