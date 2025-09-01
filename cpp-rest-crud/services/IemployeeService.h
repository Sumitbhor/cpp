#include"../entities/employee.h"
#include<vector>

#ifndef IEMPLOYEESERVICE_H
#define IEMPLOYEESERVICE_H
using namespace std;

class IEmployeeService {
    public:
        virtual ~IEmployeeService() = default;
        virtual void addEmployee(const Employee& employee) = 0;
        virtual void updateEmployee(int id, const Employee& employee) = 0;
        virtual void removeEmployee(int id) = 0;
        virtual Employee getEmployee(int id) const = 0;
        virtual vector<Employee> getAllEmployees() const = 0;
};

#endif   
