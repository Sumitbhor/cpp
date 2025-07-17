#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std ;

class student   
{
private:
    string name ;
    int age;
    string courseName;
public:
    //default constructor
    student(){
        this ->name = "sumit" ;
        this -> age =19;
        this ->courseName= "B.E computer engg";
    }
    //paramerrised constructor
    student(string name , int age , string course ){
        this -> name=name ;
        this -> age=age ;
        this -> courseName=course ;
    }

    void serialize( ofstream & fout){
        fout<<name<< age<< courseName<<endl;
    }

    void deserialize(ifstream & fin ){
        getline(fin, name);
        fin>>age;
        getline(fin, courseName);

    }
    //~student();
};

class filemanager {
    public :
    bool serlialize ( vector<student>&allstudents){
        bool status = false ;

        ofstream outFile ("student.txt");
        if (outFile.is_open()){

            for (int i = 0; i<allstudents.size(); i++){

                allstudents[i].serialize(outFile);
                status=true;
            }
            outFile.close();
            cout<<"All files are stored in file "<<endl;    
        }
        else {
            cout<<"something is wrong "<<endl;
        }
        return status;
    }
};

int main(){
    cout<<"welcome"<<endl;

    student s1 (" sanika ",20, " B.E comp ");
    student s2 (" om ",21, " B.tech comp ");
    student s3 (" nikhil ",19, " B.tech a.i ");
    student s4 ();

    vector <student> students ;
    students.push_back(s1);
    students.push_back(s2);
    students.push_back(s3);

    filemanager manager ;

    if (manager.serlialize(students)){
        cout << "all are saved"<<endl;
    }
    
}