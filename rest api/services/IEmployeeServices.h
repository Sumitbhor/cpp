#ifndef IEMPLOYEESERVICES_H
#define IEPLOYEESERVICES_H
#include "../repository/EmployeeRepository.h"
class IEmployeeservices
{

public:
    virtual ~IEmployeeservices()=default;
    virtual void addEmployee(Employee &employee)=0;
    virtual void removeEmployee(int id)=0;
    virtual void updateEMployee(int id , Employee &employee)=0;
    virtual Employee getEmployee(int id )=0;
    virtual vector<Employee>getAllemployees()=0;
};

#endif
