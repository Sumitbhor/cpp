#include"EmployeeRepository.h"
#include"../entitity/employee.h"
#include"../IO/FileIoManager.h"

#include<vector>
#include<algorithm>
using namespace std ;

void EmployeeRepository::add(Employee &employee){
    FileIoManager mgr ;
    vector<Employee>employees = mgr.readfile("employee.txt");
    employees.push_back(employee);
    mgr.writefile("employee.txt", employees);
} 

void EmployeeRepository::update(int id , Employee &employee ){
    FileIoManager mgr ;
    vector<Employee> employees=mgr.readfile ("employee.txt");
    for(auto & e : employees){
        if (e.id==id){
            e= employee ;
            break ;
        }
    }
    mgr.writefile("employee.txt", employees );
}

void EmployeeRepository::remove (int id ){
    FileIoManager mgr ;
    vector<Employee> employees=mgr.readfile ("employee.txt");
    employees.erase(remove_if(employees.begin(), employees.end(),
            [id](const Employee& p) { return p.id == id; }), employees.end());
    mgr.writefile("employee.txt", employees );
}

Employee EmployeeRepository:: get(int id ){
    FileIoManager mgr ;
    vector<Employee> employees=mgr.readfile ("employee.txt");
    for (const auto& e : employees) {
        if (e.id == id) {
            return e;
        }
    }
    return Employee{}; 
}
vector<Employee>EmployeeRepository::getAllEmployees(){
    FileIoManager mgr ;
    vector<Employee> employees=mgr.readfile ("employee.txt");
    return employees ;
}