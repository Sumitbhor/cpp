#include <fstream>
#include <sstream>
#include "../entitity/employee.h"
#include "FileIoManager.h"
#include <string>

using namespace std ;

void FileIoManager::writefile(const string & filename, vector<Employee>&employees){
    ofstream out(filename);
    if (!out.is_open())
    {
        throw runtime_error("Cloud not open file for writing ");
    }

    for(auto &emp : employees){
        out<<emp.id<<","<<emp.name<<","<<emp.salary<<","<<emp.experience<<","<<emp.age<<"\n";
    }
}

vector<Employee> FileIoManager :: readfile(const string & filename){
    ifstream in(filename);
    if (!in.is_open())
    {
        throw runtime_error("Cloud not open file for writing ");
    }
    vector<Employee>employees;
    string line ;
    while (getline(in, line))
    {
        istringstream iss (line);
        Employee emp ; 
        string token ;
        if (getline(iss, token , ','))
        {
            emp.id = stoi(token);
        }
        if (getline(iss, token , ',')){
            emp.name = token ;
        }
        if (getline(iss, token , ',')){
            emp.salary= stoi(token);
        }
        if (getline(iss, token , ',')){
            emp.experience= stoi(token);
        }
        if (getline(iss, token , ',')){
            emp.age= stoi(token);
        }
        if (!emp.name.empty()){
            employees.push_back(emp);
        }
    }
    return employees;
}