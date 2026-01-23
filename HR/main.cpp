#include "./Employee.cpp"
#include <iostream>
using namespace std ;

int main(){
    Employee emp(1 ,"sumit", "bhor", "sumit227@gmial.com","853008699","manchar", 50000,10000, 5000  );
    string emp1= emp.to_String();
    cout<<emp1<<endl ;
}