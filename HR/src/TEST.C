#include <stdio.h>

// /* Employee structure */
// struct Employee {

//     int id;
//     char name[20];
//     float baseSalary;

//     /* Function pointer for salary calculation */
//     float (*calculateSalary)(float);
// };

// /* Salary calculation for Normal Employee */
// float   normalSalary(float base) {
//     return base;
// }

// /* Salary calculation for Sales Employee */
// float salesSalary(float base) {
//     return base + (base * 0.20);   // 20% commission
// }

// /* Assign salary calculation method */
// void setSalaryMethod(struct Employee* emp, float (*func)(float)) {
//     emp->calculateSalary = func;
// }

// /* Display employee details */
// void display(struct Employee* emp) {

//     float totalSalary = emp->calculateSalary(emp->baseSalary);

//     printf("\nEmployee ID   : %d", emp->id);
//     printf("\nName          : %s", emp->name);
//     printf("\nBase Salary   : %.2f", emp->baseSalary);
//     printf("\nTotal Salary  : %.2f\n", totalSalary);
// }

// /* Main */
// int main() {

//     /* Normal Employee */
//     struct Employee emp1 = {101, "Rahul", 30000, NULL};

//     /* Sales Employee */
//     struct Employee emp2 = {102, "Amit", 30000, NULL};

//     /* Set salary calculation */
//     setSalaryMethod(&emp1, normalSalary);       
//     setSalaryMethod(&emp2, salesSalary);

//     /* Display */
//     display(&emp1);
//     display(&emp2);

//     return 0;
// }
void change (int *ptr){
    *ptr = 25 ;
}

int main (){
    int x= 100;
    change(&x);
    printf("%d", x);
    
}