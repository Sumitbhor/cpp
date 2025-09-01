#include<iostream>
using namespace std;
class staticdemo {
    public:
    int a= 0;
    static int b;
     void incrementA() {
        a++;
        cout<<"A="<<a<<endl;
        cout<<"Address A: %"<<&a<<endl;  
    }
    static void incrementB() {
        b++;
        cout<<"B="<<b<<endl;
        cout<<"Address B:"<<&b<<endl;
    }
};
int staticdemo:: b= 0;
int main() {
    staticdemo s1,s2,s3,s4,s5;
    s1.a=10;
    s1.incrementA();
    staticdemo::incrementB();
    
    s2.incrementA();
    staticdemo::incrementB();
    
    // s3.incrementA();
    // staticdemo::incrementB();
    
    // s4.incrementA();
    // staticdemo::incrementB();
    
    // s5.incrementA();
    // staticdemo::incrementB();
    
    return 0;
}



