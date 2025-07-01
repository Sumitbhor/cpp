#include"../include/SalesEmployee.h"
#include<iostream>
using namespace std;
salesEmployee::salesEmployee(){
    target =0;
    insentive=0.0;
}
salesEmployee::salesEmployee(int empid, string empname, double salary,int emptarget , double empInsentive):Employee(id,name,salary){
    target=emptarget;
    insentive=empInsentive;
}
void salesEmployee::displayInfo(){
    cout<<"target"<<target<<"\ninsentive"<<insentive;
}
salesEmployee::~salesEmployee() {
    // Destructor implementation (if needed)
    cout << "Sales Employee object having target " << target << " is being destroyed." << endl;
}