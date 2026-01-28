#include <iostream>
using namespace std;
#include <string>
#include "../include/SalesEmployee.h"
void SalesEmployee ::doWork()
{
    cout << "do your work " << endl;
}

double SalesEmployee ::computePay()
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

void SalesEmployee ::Conduct_Appraisable()
{
    cout << "\nSales Employee appraisal completed." << endl;
}
