#include<iostream>
using namespace std ;

class Shape
{
public:
    virtual void draw (){
        cout<<"Drawing a generic shape"<<endl ;
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
    Shape draw ;
    draw.draw();
    Shape * shape1 = new Circle();
    
    Shape * shape2 = new Rectangle();
    
    shape1-> draw();
    shape2-> draw();


    return 0;
}
