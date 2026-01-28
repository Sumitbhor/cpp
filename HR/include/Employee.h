#ifndef Employee_h
#define Employee_h
#include <iostream>
#include <string>
using namespace std;
class Employee
{
public:
    int id;
    string firstname;
    string lastname;
    string email;
    string phone;
    string city;
    double baseSalary;
    double HRA;
    double Allowance;

    Employee() {}
    Employee(int id, string firstname, string lastname, string email, string phone, string city, double salary, double HRA, double Allowance)
    {

        this->id = id;
        this->firstname = firstname;
        this->lastname = lastname;
        this->email = email;
        this->baseSalary = salary;
        this->city = city;
        this->phone = phone;
        this->HRA = HRA;
        this->Allowance = Allowance;
    }
    virtual void doWork() = 0;
    double computePay();
    string to_String();
};
#endif