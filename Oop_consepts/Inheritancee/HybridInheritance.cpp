#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Eating food." << endl;
    }
};

class Mammal {
public:
    void giveBirth() {
        cout << "Giving birth to live young." << endl;
    }
};

class Dog : public Animal, public Mammal {
public:
    void bark() {
        cout << "Barking!" << endl;
    }
};

class Labrador : public Dog {
public:
    void specialBehavior() {
        cout << "Labrador special behavior!" << endl;
    }
};

int main() {
    Labrador lab;
    lab.eat();             // Inherited from Animal
    lab.giveBirth();       // Inherited from Mammal
    lab.bark();            // Inherited from Dog
    lab.specialBehavior(); // Defined in Labrador

    return 0;
}