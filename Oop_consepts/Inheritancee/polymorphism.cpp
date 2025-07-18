#include<iostream>
using namespace std ;

class Employee
{

public:
   float basicSalary;
   float incometax;

   virtual void computePay()
   {
    float package=basicSalary-incometax;
    cout<<"Take Home Salary  " << package <<endl ;
   }
};

class Manager : public Employee 
{
    public:
        float incentive;
      void computePay() override
    {
         float package=(basicSalary-incometax)+ incentive;
        cout<<"Manager Take Home Salary  " << package <<endl ;
    }
};

int main()
{ 


    Employee emp;
    emp.basicSalary=34000;
    emp.incometax=5000;
    emp.computePay();

    Manager mgr;
    mgr.basicSalary=34000;
    mgr.incometax=5000;
    mgr.incentive=23000;
    mgr.computePay();

   Employee * pEmployee1=&emp;

    Employee * pEmployee2=&mgr;

    //polymorphism

    pEmployee1->computePay();
    pEmployee2->computePay();
    
    return 0;
}
