#include<..\entities\employee.h>
#include<vector>
#include"IemployeeRepository.h"
using namespace std;
#ifndef EMPLOYEEREPOSITORY_H
#define EMPLOYEEREPOSITORY_H

class EmployeeRepository : public IEmployeeRepository {
    
    public:
        vector<Employee> employees;
        void addEmployee(const Employee& employee);
        void removeEmployee(int id);
        void updateEmployee(const Employee& employee);
        Employee* getEmployee(int id);
        vector<Employee> getAllEmployees();
};

#endif // EMPLOYEEREPOSITORY_H