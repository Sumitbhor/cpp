#include<iostream>
using namespace std ;
class Animal {
    public :
        void eat(){
            cout<<"Eating Food "<<endl ;
        }
};

class Mammal : public Animal  {
    public :
         void giveBirth(){
            cout<<"Giving birth to live young "<<endl ;
         }
};

class Dog : public Mammal {
public :
    void bark (){
        cout<< "Barkin !"<< endl ;
    }
};

int main(int argc, char const *argv[])
{
    Dog dog ;
    dog.giveBirth() ;
    dog.bark();
    dog.eat();


    return 0;
}
