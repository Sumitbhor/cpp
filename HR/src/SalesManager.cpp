#include <iostream>
using namespace std;
#include <string>
#include "..\include\SalesManager.h"



    void SalesManager::doWork() 
    {
        cout << "do your work " << endl;
    }

    double SalesManager::computePay() 
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

    float SalesManager::CalculateBonus() 
    {
        return this->bonus;
    }
    void SalesManager::Conduct_Appraisable() 
    {
        cout << "\nManager appraisal completed.";
    }

    void SalesManager::ApproveLeaves() 
    {
        cout << "\nLeave approved by Sales Manager.";
    }

    void SalesManager::TakeInterview() 
    {
        cout << "\nSales Manager conducting interview.";
    }

    void SalesManager::Train() 
    {
        cout << "\nSales Manager training sales team.";
    }

