#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Eating food." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking!" << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "Meowing!" << endl;
    }
};

int main() {
    Dog dog;
    dog.eat();  // Inherited from Animal
    dog.bark(); // Defined in Dog

    Cat cat;
    cat.eat();  // Inherited from Animal
    cat.meow(); // Defined in Cat

    return 0;
}