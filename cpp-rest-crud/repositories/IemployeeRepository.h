#include "../entities/employee.h"
#include <vector>
#ifndef IEMPLOYEEREPOSITORY_H
#define IEMPLOYEEREPOSITORY_H
class IEmployeeRepository {
    public:
        virtual ~IEmployeeRepository() = default;
        virtual void addEmployee(const Employee& employee) = 0;
        virtual void updateEmployee(int id, const Employee& employee) = 0;
        virtual void removeEmployee(int id) = 0;
        virtual Employee getEmployee(int id) const = 0;
        virtual std::vector<Employee> getAllEmployees() const = 0;
};

#endif 
