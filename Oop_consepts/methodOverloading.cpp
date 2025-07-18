#include<iostream>
#include<string>
using namespace std ;

class Products
{
private:
    int num1 ;
    int num2 ; 
    int sum;
    static int count;

public:
//default constuctor 
    Products()
    {
        cout<<"default constuctor call"<<endl;
       num1=10;
       num2=20;
    }

    Products(int num1, int num2)
    {
        cout<<"parameterised constuctor call"<<endl;
        this->num1=num1;
        this->num2=num2;
    }

    Products(Products &p4) { 
        cout<<"Copy constuctor call"<<endl;
        this->num1=p4.num1;
        this->num2=p4.num2;
    }

    int getNum1()
    {
        return num1;
    }

    void setNum1(int num1)
    {
        this->num1=num1;
    }
    
    int getNum2()
    {
        return num2;
    }

    void setNum2(int num2)
    {
        this->num1=num2;
    }
    
    void addition(/*int n1,int n2*/)
    {
      int add=num1+num2;
      cout<<"Addition: "<<add<<endl;
    }

    // void addition(int n1,int n2,int n3)
    // {
    //     int add=n1+n2+n3;
    //     cout<<"Addition: "<<add;
    // }

  
    void display()
    {
        cout<<"addition: "<<sum<<endl;
    }

    ~Products()
    {
        cout<<"destuctor call"<<++count<<endl;
    }
};
int Products::count=0;

int main()
{

    Products p1;
    // p1.addition(30,40);
    // p1.addition(60,40,80);
    p1.addition();

     Products p2(50,60);
    //  p2.addition(10,20);
    //  p2.display();
    p2.addition();

    Products p3(p2); 
    p3.addition();

    return 0;
}
