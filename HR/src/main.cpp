#include "../include/Employee.h"
#include"../include/SalesEmployee.h"
#include"../include/SalesManager.h"
#include <string>

using namespace std;

int main()
{

    SalesManager manager(2, "rahul", "shinde", "rahulshinde@gmail.com", "9876543210", "pune", 60000, 12000, 6000, 5000, 10, 12, 800);
    IAppraisable *appraisable = &manager;
    appraisable->Conduct_Appraisable();

    IBonusEligible *bonusEligible = &manager;
    float bonus = bonusEligible->CalculateBonus();

    IInterviewPanel *interviewPanel = &manager;
    interviewPanel->TakeInterview();

    ITrainer *trainer = &manager;
    trainer->Train();     
    
    
}
/*

g++ -I include -c ./src/Employee.cpp -o ./build/Employee.o
g++ -I include -c ./src/SalesEmployee.cpp -o ./build/SalesEmployee.o
g++ -I include -c ./src/SalesManager.cpp -o ./build/SalesManager.o
g++ -I include -c ./src/main.cpp -o ./build/main.o
g++ ./build/SalesManager.o ./build/SalesEmployee.o ./build/Employee.o ./build/main.o -o ./build/main.exe

*/