#include<vector>
#include"../entities/employee.h"
#include"IemployeeService.h"
#include"../repositories/IemployeeRepository.h"
#ifndef EMPLOYEESERVICE_H
#define EMPLOYEESERVICE_H
using namespace std;
class EmployeeService : public IEmployeeService {
    public:
        IEmployeeRepository * repository;
        EmployeeService(IEmployeeRepository * repository);
        virtual ~EmployeeService () = default;
        virtual void addEmployee(const Employee& employee);
        virtual void updateEmployee(int id, const Employee& employee);
        virtual void removeEmployee(int id);
        virtual Employee getEmployee(int id) const;
        virtual vector<Employee> getAllEmployees() const;
};

#endif 