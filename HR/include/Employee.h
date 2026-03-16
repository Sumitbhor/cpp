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
    Employee(int id, string firstname, string lastname, string email, string phone, string city, double salary, double HRA, double Allowance): id(id), firstname(firstname), lastname(lastname), email(email), phone(phone), city(city), baseSalary(salary), HRA(HRA), Allowance(Allowance)
    {
        
    }
    virtual void doWork() = 0;
    double computePay();
    string to_String();
};
#endif