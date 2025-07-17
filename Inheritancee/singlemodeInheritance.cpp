#include<iostream>
using namespace std ;
class Animal
{

public:
    void eat () {
        cout<<"Eating Food"<<endl ;
    }
};

class Dog : public Animal
{

public:
   void bark(){
    cout<<"barking ! " << endl ;
    }
};

int main(int argc, char const *argv[])
{
    Dog dog ;
    dog.eat();
    dog.bark();
    return 0;
}


