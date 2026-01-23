#include <iostream>
using namespace std;
#include <string>
#include "./Employee.cpp"

class SalesEmployee : public Employee
{

public:
    double incentive;
    int target;
    int achiveTarget;

    SalesEmployee(int id, string firstname, string lastname, string email, string phone, string city, double salary, double HRA, double Allowance, double incentive, int target, int achiveTarget)
    {
        this->id = id;
        this->firstname = firstname;
        this->lastname = lastname;
        this->email = email;
        this->phone = phone;
        this->city = city;
        this->salary = salary;
        this->HRA = HRA;
        this->Allowance = Allowance;
        this->incentive = incentive;
        this->target = target;
        this->achiveTarget = achiveTarget;
    }
    void doWork()
    {
        cout << "do your work " << endl;
    }

    double computePay() override
    {
        if (this->target <= this->achiveTarget)
        {
            double totalsalary = this->salary + this->HRA + this->Allowance + this->incentive;
        }
        else
        {
            double totalsalary = this->salary + this->HRA + this->Allowance;
        }
    }
};
