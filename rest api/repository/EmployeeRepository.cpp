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
    vector<Employee>employees={
        {1,"sumit",100000, 4,19},
        {2,"sanika",200000, 6,19},
        {3,"sarthak",300000, 7,19},
        {4,"pankaj",400000, 7,19}
    };
    return employees ;
}