#include <iostream>
using namespace std;
#include <string>
#include "./SalesEmployee.cpp"
#include "./interface/IManagerBenefits.h"
#include "./interface/IInterviewPanel.h"
#include "./interface/ITrainer.h"
#ifndef SalesManager_h
#define SalesManager_h

class SalesManager : public SalesEmployee,
                     public IManagerBenefits,
                     public IInterviewPanel,
                     public ITrainer

{

public:
    float bonus;

    SalesManager(int id,
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
                 int achiveTarget,
                 float bonus):SalesEmployee(id,firstname,lastname,email,phone,city,baseSalary,HRA,Allowance,incentive,target,achiveTarget)
    {
        this->bonus = bonus;
    }
    void doWork() override
    {
        cout << "do your work " << endl;
    }

    double computePay() override
    {
        if (this->target <= this->achiveTarget)
        {
            return this->baseSalary + this->HRA + this->Allowance + this->incentive;
        }
        else
        {
            return this->baseSalary + this->HRA + this->Allowance;
        }
    }

    float CalculateBonus() override
    {
        return this->bonus;
    }
    void Conduct_Appraisable() override
    {
        cout << "\nManager appraisal completed.";
    }

    void ApproveLeaves() override
    {
        cout << "\nLeave approved by Sales Manager.";
    }

    void TakeInterview() override
    {
        cout << "\nSales Manager conducting interview.";
    }

    void Train() override
    {
        cout << "\nSales Manager training sales team.";
    }
};
#endif