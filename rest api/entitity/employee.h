#ifndef ENTITY_EMPLOYEE_H
#define ENTITY_EMPLOYEE_H

#include <string>
using namespace std;
class Employee {
    public:
        int id;
        string name;
        double salary;
        int experience; 
        int age;
    Employee(){
        
    }
    Employee(int id , string name , double salary , int experience , int age) {
        this->id = id;
        this->name = name;
        this->salary = salary;
        this->experience = experience;
        this->age = age;
    }
};
#endif