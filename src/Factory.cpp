#include "../include/Factory.h"
#include "../include/Project.h"
#include "../include/Engineer.h"
std::vector<Employee *> Factory_Staff::make_staff() {
    std::ifstream file;
    file.open("../bd/projects_info.txt");
    int id, budget, num_of_workers;
    std::string line;
    std::vector<Project *>projects_from_file;
    std::vector<Employee *>workers_from_file;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> id >> budget >> num_of_workers;
        projects_from_file.push_back(new Project(id, budget, num_of_workers));
    }
    file.close();
    file.open("../bd/staff_info.txt");
    int work_time, payment, project_id;
    std::string name, surname, lastname, fullname, position;
    while (std::getline(file,line)) {
        std::istringstream iss(line);
        iss >> id >> name >> surname >> lastname >> payment >> work_time >> position;
        fullname = name + " " + surname + " " + lastname;
        if (position == "programmer") {
            iss >> project_id;
            for (int i = 0; i < projects_from_file.size(); i++) {
                if (project_id == projects_from_file[i]->get_id()) {
                    workers_from_file.push_back(new Programmer(id, fullname, Positions::programmer, work_time,
                    payment, projects_from_file[i]));
                    projects_from_file[i]->plus_programmer();
                }
            }
        }
        else if (position == "tester") {
            iss >> project_id;
            for (int i = 0; i < projects_from_file.size(); i++) {
                if (project_id == projects_from_file[i]->get_id()) {
                    workers_from_file.push_back(new Tester(id, fullname, Positions::tester, work_time,
                    payment, projects_from_file[i], rand()%10));
                    projects_from_file[i]->plus_programmer();
                    
                }
            }
        }
        else if (position == "team_leader") {
            iss >> project_id;
            for (int i = 0; i < projects_from_file.size(); i++) {
                if (project_id == projects_from_file[i]->get_id()) {
                    workers_from_file.push_back(new TeamLeader(id, fullname, Positions::team_leader, work_time,
                    payment, projects_from_file[i]));
                }
            }
        }
        else if (position == "project_manager") {
            iss >> project_id;
            std::vector<Project*> ready_project;
            for (int i = 0; i < projects_from_file.size(); i++) {
                if (project_id == projects_from_file[i]->get_id()) {
                    ready_project.push_back(projects_from_file[i]);
                    workers_from_file.push_back(new ProjectManager(id, fullname, work_time, payment, Positions::project_manager,
                    ready_project));
                }
            }
        }
        else if (position == "senior_manager") {
            std::vector<int>projects_id;
            int project_id;
            while (iss >> project_id) {
                projects_id.push_back(project_id);
            }
            std::vector<Project*> ready_projects;
            for (int i = 0; i < projects_id.size(); i++) {
                for (int j = 0; j < projects_from_file.size(); j++){
                    if (projects_id[i] == projects_from_file[j]->get_id()) {
                        ready_projects.push_back(projects_from_file[j]);
                    }
                }
            }
            workers_from_file.push_back(new SeniorManager(id, fullname, work_time, payment, Positions::senior_manager,
            ready_projects)); 
        }
        else if (position == "driver") {
            workers_from_file.push_back(new Driver(id, fullname, work_time, Positions::driver, payment));
        }
        else {
            workers_from_file.push_back(new Cleaner(id, fullname, work_time, Positions::cleaner, payment));
        }
    }
    return workers_from_file;
}