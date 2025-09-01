#include<iostream>
using namespace std ;

class Employee
{

public:
   string name ;
   int id ;  

   void displayInfo()
   {
    cout<<"Name " << name <<" , Id : "<<id <<endl ;
   }
};

class Manager : public Employee 
{
    public:
    void approveLeave()
    {
        cout<<name << " approved the leave " <<endl ;
    }
};

int main()
{
    Manager m ;
    m.name = "Rajesh";
    m.id = 25 ;
    m.displayInfo();
    m.approveLeave();
    return 0;
}