#include <iostream>
using namespace std;
#include <string>
#include "Employee.h"
#include "IAppraisable.h"
#include "IBonusEligible.h"
#ifndef ISalesEmployee_h
#define ISalesEmployee_h

class ISalesEmployee : public Employee,
                      public IAppraisable,
                      public IBonusEligible
{

public:
    double incentive;
    int target;
    int achiveTarget;

    virtual void doWork() =0;

    virtual double computePay() =0;
    

    void Conduct_Appraisable()=0 ;
};
#endif