#include <stdio.h>
//simple pointer

int  (*listener) (int , int);  //function pointer
//it always stores address of function

int onRequest(int num1, int num2)
 {
     return num1 + num2;
 }

 
 
int main() {
   //invoke function  (direct function invokation)
   // int result=addition(56,76);
   //indirect function invokation
    listener=onRequest;
    int result=listener(76,2);  //calling function pointer
    printf("Result = %d", result);
   return 0;
}