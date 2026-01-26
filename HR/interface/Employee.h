#include "IEmployee.h"
#ifndef Employee_h
#define Employee_h
class Employee : public IEmployee
{
public:
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
    void doWork() override;
    double computePay() override;
    string to_String() override;
};
#endif