#include <iostream>
using namespace std;
#include <string>
#include "ISalesEmployee.h"
#ifndef SalesEmployee_h
#define SalesEmployee_h

class SalesEmployee : public ISalesEmployee

{

public:
    SalesEmployee()
    {
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
                  int achiveTarget);
    void doWork() override;

    double computePay() override;

    void Conduct_Appraisable() override;
};
#endif