#include"employeeRepository.h"
#include <algorithm>
using namespace std;
    void EmployeeRepository::addEmployee(const Employee& employee) {
        employees.push_back(employee);  
    }

    void EmployeeRepository::removeEmployee(int id) {
        employees.erase(remove_if(employees.begin(), employees.end(),
            [id](const Employee& e) { return e.id == id; }), employees.end());
    }
    void EmployeeRepository::updateEmployee(const Employee& employee) {
        for (auto& e : employees) {
            if (e.id == employee.id) {
                e = employee;
                break;
            }
        }
    }
    Employee* EmployeeRepository::getEmployee(int id) {
        for (auto& e : employees) {
            if (e.id == id) {
                return &e;
            }
        }
        return nullptr; // Return nullptr if employee not found
    }
    vector<Employee> EmployeeRepository::getAllEmployees() {
        return employees;
    }
