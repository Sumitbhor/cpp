
using namespace std;
#include <string>
#ifndef IEmployee_h
#define IEmployee_h
class IEmployee
{
public:
    int id;
    string firstname;
    string lastname;
    string email;
    double baseSalary;
    string city;
    string phone;
    double HRA;
    double Allowance;
    virtual void doWork() = 0;

    virtual double computePay() = 0;

    virtual string to_String() = 0;
};
#endif