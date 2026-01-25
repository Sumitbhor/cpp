#include "./Employee.cpp"
#include <string>
#include "./SalesManager.cpp"
using namespace std;

int main()
{
    // Employee emp(1 ,"sumit", "bhor", "sumit227@gmial.com","853008699","manchar", 50000,10000, 5000  );
    // string emp1= emp.to_String();
    // cout<<emp1<<endl ;

    SalesManager manager(2, "rahul", "shinde", "rahulshinde@gmail.com", "9876543210", "pune", 60000, 12000, 6000, 5000, 10, 12, 800);
    IAppraisable *appraisable = &manager;
    appraisable->Conduct_Appraisable();

    IBonusEligible *bonusEligible = &manager;
    float bonus = bonusEligible->CalculateBonus();

    IInterviewPanel *interviewPanel = &manager;
    interviewPanel->TakeInterview();

    ITrainer *trainer = &manager;
    trainer->Tain();          
}
/*
g++ -I include -c Employee.cpp -o build/Employee.o
g++ -I include -c SalesEmployee.cpp -o build/SalesEmployee.o
g++ -I include -c SalesManager.cpp -o build/SalesManager.o
g++ -I include -c main.cpp -o build/main.o
cd build
g++ -I include main.o SalesManager.o SalesEmployee.o Employee.o -o main.exe
*/