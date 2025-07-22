#include<iostream>
using namespace std ;

//abstract class
//pure abstract base class
class Shape
{
public:
    virtual void draw ()=0;
    void display()
    {
        cout<<"ok";
    }
};

class Circle : public Shape {
public :
    void draw() override{
        cout<<"Drawing a Circle"<<endl;
    }
};

class Rectangle : public Shape {
public :
    void draw() override{
        cout<<"Drawing a rectangle"<<endl;
    }
};

int main()
{   
  //  Shape draw ;
    // draw.draw();
    Shape * shape1 = new Circle();
    Shape * shape2 = new Rectangle();
    
    shape1-> draw();
    shape2-> draw();
    shape1->display();


    return 0;
}
