#include "ISalesManager.h"
#include <iostream>
using namespace std;

class SalesManager : public ISalesManager
{
public:
    SalesManager();
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
                 float bonus);
    void doWork() override;

    double computePay() override;

    float CalculateBonus() override;

    void Conduct_Appraisable() override;

    void ApproveLeaves() override;

    void TakeInterview() override ;

    void Train() override ;
};


