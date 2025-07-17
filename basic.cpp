#include<iostream>
#include<string>
using namespace std ;

class Products
{
private:
    int num1 ;
    int num2 ; 
    // int sum;

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
    // void addition()
    // {
    //    sum=num1+num2;   
    // }
  
    // void display()
    // {
    //     cout<<"addition: "<<sum<<endl;
    // }

    ~Products()
    {
        cout<<"destuctor call"<<endl;
    }
};

void addition(int n1, int n2)
{
     int sum=n1+n2;
     cout<<"Addition: "<<sum<<endl;
}

int main()
{
    
     Products p2(50,60);
     int n1=p2.getNum1();
     int n2=p2.getNum2();
     addition(n1,n2);

    // Products p1;
    // p1.addition();
    // p1.display();


    //  Products p2(50,60);
    //  p2.addition();
    //  p2.display();
    return 0;
}
