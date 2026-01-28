
#include <iostream>
#include"../include/SalesEmployee.h"
#include"../include/interfaces/IManagerBenefits.h"
#include"../include/interfaces/IInterviewPanel.h"
#include"../include/interfaces/ITrainer.h"
#include"../include/interfaces/IBonusEligible.h"
#include <string>
using namespace std;

class SalesManager : public SalesEmployee,public IManagerBenefits, public IInterviewPanel, public ITrainer, public IBonusEligible
{
public:
    float bonus;
    SalesManager();
    SalesManager(int id,string firstname, string lastname, string email,string phone, string city, double baseSalary, double HRA, double Allowance,double incentive, int target, int achiveTarget, float bonus):SalesEmployee(id, firstname, lastname, email, phone, city, baseSalary, HRA, Allowance, incentive, target, achiveTarget)
    {
        this->bonus = bonus;
    }
    void doWork()override ;

    double computePay() ;

    float CalculateBonus() ;

    void Conduct_Appraisable() ;

    void ApproveLeaves() ;

    void TakeInterview()  ;

    void Train()  ;
};


