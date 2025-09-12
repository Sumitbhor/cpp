#include"employeeRepository.h"
#include<vector>
#include<algorithm>
using namespace std ;

void EmployeeRepository::add(Employee &employee){
    
    employees.push_back(employee);
}

void EmployeeRepository::update(int id , Employee &employee ){
    for(auto & e : employees){
        if (e.id==id){
            e= employee ;
            break ;
        }
    }
}

void EmployeeRepository::remove (int id ){
    employees.erase(remove_if(employees.begin(), employees.end(),
            [id](const Employee& p) { return p.id == id; }), employees.end());

}

Employee EmployeeRepository:: get(int id ){
    for (const auto& e : employees) {
        if (e.id == id) {
            return e;
        }
    }
}
vector<Employee>EmployeeRepository::getAllEmployees(){
    return employees ;
}