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
        this->baseSalary = 0;
        this->HRA = 0;
        this->Allowance = 0;
        this->incentive = 0;
        this->target = 0;
        this->achiveTarget = 0;
    }

    SalesEmployee(int id,
                  string firstname,
                  string lastname,
                  string email,
                  string phone,
                  string city,
                  double baseSalary,
                  double HRA,
                  double Allowance,
                  double incentive,
                  int target,
                  int achiveTarget) : Employee(id, firstname, lastname, email, phone, city, baseSalary, HRA, Allowance)
    {
        this->incentive = incentive;
        this->target = target;
        this->achiveTarget = achiveTarget;
    }
    void doWork() override
    {
        cout << "do your work " << endl;
    }

    double computePay() override
    {
        if (this->target <= this->achiveTarget)
        {
            double totalsalary = this->baseSalary + this->HRA + this->Allowance + this->incentive;
        }
        else
        {
            double totalsalary = this->baseSalary + this->HRA + this->Allowance;
        }
    }

    void Conduct_Appraisable() override
    {
        cout << "\nSales Employee appraisal completed." << endl;
    }
};
#endif