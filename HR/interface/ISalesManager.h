#include <iostream>
using namespace std;
#include <string>
#include "./SalesEmployee.cpp"
#include "./interface/IManagerBenefits.h"
#include "./interface/IInterviewPanel.h"
#include "./interface/ITrainer.h"
#ifndef SalesManager_h
#define SalesManager_h

class ISalesManager : public SalesEmployee,
                      public IManagerBenefits,
                      public IInterviewPanel,
                      public ITrainer
{
public:
    float bonus;

    virtual void doWork() = 0;
    virtual double computePay() = 0;
    virtual float CalculateBonus() = 0;
    virtual void Conduct_Appraisable() = 0;
    virtual void ApproveLeaves() = 0;
    virtual void TakeInterview() = 0 ;
    virtual void Train() = 0;
};
#endif
