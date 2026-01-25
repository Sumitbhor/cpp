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
                 double salary,
                 double HRA,
                 double Allowance,
                 double incentive,
                 int target,
                 int achiveTarget,
                 float bonus):SalesEmployee(id,firstname,lastname,email,phone,city,salary,HRA,Allowance,incentive,target,achiveTarget)
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
            return this->salary + this->HRA + this->Allowance + this->incentive;
        }
        else
        {
            return this->salary + this->HRA + this->Allowance;
        }
    }

    float CalculateBonus() override
    {
        return this->bonus;
    }
    void Conduct_Appraisable() override
    {
        cout << "Manager appraisal completed.";
    }

    void ApproveLeaves() override
    {
        cout << "Leave approved by Sales Manager.";
    }

    void TakeInterview() override
    {
        cout << "Sales Manager conducting interview.";
    }

    void Tain() override
    {
        cout << "Sales Manager training sales team.";
    }
};
#endif