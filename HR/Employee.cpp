#include <iostream>
using namespace std;
#include <string>
#ifndef Employee_cpp
#define Employee_cpp
class Employee
{
public:
    int id;
    string firstname;
    string lastname;
    string email;
    double salary;
    string city;
    string phone;
    double HRA;
    double Allowance;

    Employee()
    {

    }

    Employee(int id, string firstname, string lastname, string email, string phone, string city, double salary, double HRA, double Allowance)
    {

        this->id = id;
        this->firstname = firstname;
        this->lastname = lastname;
        this->email = email;
        this->salary = salary;
        this->city = city;
        this->phone = phone;
        this->HRA = HRA;
        this->Allowance = Allowance;
    }

    virtual void doWork()
    {
        cout << "Employee is working " << endl;
    }

    virtual double computePay()
    {
        return 0;
    }

    string to_String()
    {
        return "id" + to_string(this->id) + "first name" + this->firstname + "lastname " + this->lastname + "email" + this->email + "salary " + to_string(this->salary) + "city " + this->city + "phone " + this->phone + "HRA " + to_string(this->HRA) + "Allowance" + to_string(this->Allowance);
    }
};
#endif