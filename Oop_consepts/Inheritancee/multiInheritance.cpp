#include <iostream>
using namespace std ;

class Animal{
    public :
    void eat(){
        cout<<"Eating food. " <<endl ;
    }
};

class Mammal{
public : 
    void walk(){
        cout<<"Walking on land ." << endl ;
    }
};

class Dog: public Animal , public Mammal {
    public :
        void bark() {
            cout<<"Barking  ! " << endl ;
        }
};

int main(int argc, char const *argv[])
{
    Dog dog ;
    dog.eat();
    dog.walk();
    dog.bark();
    return 0;
}

 