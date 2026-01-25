#include <iostream>
using namespace std;
#include <string>
#include "./Employee.cpp"
#include "./interface/IAppraisable.h"
#include "./interface/IBonusEligible.h"
#ifndef SalesEmployee_h
#define SalesEmployee_h

class SalesEmployee : public Employee,
                      public IAppraisable,
                      public IBonusEligible
{

public:
    double incentive;
    int target;
    int achiveTarget;
    SalesEmployee()
    {
        this->id = 0;
        this->firstname = "";
        this->lastname = "";
        this->email = "";
        this->phone = "";
        this->city = "";
        this->salary = 0;
        this->HRA = 0;
        this->Allowance = 0;
        this->incentive = 0;
        this->target = 0;
        this->achiveTarget = 0;
    }

    SalesEmployee(int id, string firstname, string lastname, string email, string phone, string city, double salary, double HRA, double Allowance, double incentive, int target, int achiveTarget):Employee(id,firstname,lastname,email,phone,city,salary,HRA,Allowance)
    {
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

    void Conduct_Appraisable() override
    {
        cout << "Sales Employee appraisal completed." << endl;
    }
};
#endif