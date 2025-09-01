#ifndef EMPLOYEEREPOSITORY_H
#define EMPLOYEEREPOSITORY_H
#include"../entitity/employee.h"
#include "IemployeeRepository.h"
#include <vector>
using namespace std ;

class EmployeeRepository:public IEmployeeRepository{
    public :
        vector<Employee>employees ;
        void add(Employee &employee);
        void update (int id , Employee &employee );
        void remove(int id );
        Employee get(int id );
        vector<Employee>getAllEmployees() ;
};
#endif 