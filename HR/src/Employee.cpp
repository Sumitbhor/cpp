#include <iostream>
using namespace std;
#include <string>
#include "../include/Employee.h"
     void Employee ::doWork()
    {
        cout << "\nEmployee is working " << endl;
    }

    // double Employee :: computePay(){
    //     return this->baseSalary+ this->HRA +this->Allowance ; 
    // }

    string Employee ::to_String()
    {
        return "id" + to_string(this->id) + "first name" + this->firstname + "lastname " + this->lastname + "email" + this->email + "salary " + to_string(this->baseSalary) + "city " + this->city + "phone " + this->phone + "HRA " + to_string(this->HRA) + "Allowance" + to_string(this->Allowance);
    }   

    