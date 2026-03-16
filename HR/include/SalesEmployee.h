#include <iostream>
using namespace std;
#include <string>
#include "./Employee.h"
#include "./interfaces/IAppraisable.h"

#ifndef SalesEmployee_h
#define SalesEmployee_h

class SalesEmployee : public Employee, public IAppraisable

{

public:
    double incentive;
    int target;
    int achiveTarget;
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
                  int achiveTarget) : Employee(id, firstname, lastname, email, phone, city, baseSalary, HRA, Allowance), incentive(incentive), target(target), achiveTarget(achiveTarget)
    {
       
    }
    void doWork() override;
    double computePay();

    void Conduct_Appraisable();
};
#endif