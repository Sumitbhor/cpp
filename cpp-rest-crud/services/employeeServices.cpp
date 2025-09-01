#include"../entities/employee.h"
#include"employeeService.h"
#include"../repositories/employeeRepository.h"  
using namespace std;

EmployeeService::EmployeeService(IEmployeeRepository * repository) {
    this->repository = repository;
}

void EmployeeService::addEmployee(const Employee& employee) {
    repository->addEmployee(employee);
}
void EmployeeService::updateEmployee(int id, const Employee& employee) {
    repository->removeEmployee(id);
    repository->addEmployee(employee);
}   
void EmployeeService::removeEmployee(int id) {
    repository->removeEmployee(id);
}

Employee EmployeeService::getEmployee(int id) const {
    return repository->getEmployee(id);
}
vector<Employee> EmployeeService::getAllEmployees() const {
    return repository->getAllEmployees();
}
