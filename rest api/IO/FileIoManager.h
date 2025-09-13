#ifndef FILEIOMANAGER_H
#define FILEIOMANAGER_H
#include <string>
#include <vector>
#include "../entitity/employee.h"

using namespace std ;
class FileIoManager{
    public :
        void writefile(const string& filename, vector<Employee> &emoloyees);
        vector<Employee> readfile(const string & filename);
};

#endif // FILEIOMANAGER_H