
# include "../include/employee.h"

#include <iostream>

using namespace std;


//implementation of Employee class methods

Employee::Employee(){

    id = 0;
    name = "";
    salary = 0.0;
}

Employee::Employee( int empId, string& empName, double empSalary) {
    name = empName;
    id = empId;
    salary = empSalary;
}


void Employee::displayInfo() {
    cout << "\nEmployee ID: " << id << endl;
    cout << "\nName: " << name << endl;
    cout << "\nSalary: $" << salary << endl;
}

Employee::~Employee() {
    // Destructor implementation (if needed)
    cout << "Employee object with ID " << id << " is being destroyed." << endl;
}