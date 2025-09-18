
//must go BEFORE httplib
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define byte win_byte_override // avoid conflict with std::byte
#include <windows.h>
#undef byte
#include "httplib.h"
#include "./SQL_repository/EmployeeRepository.h"
#include "./services/EmployeeServices.h"
#include "./Controller/EmployeeController.h"
#include "./Router/EmployeeRouter.h"

using namespace httplib;

int main() {
    Server svr;

    IEmployeeRepository* empRepo = new EmployeeRepository();
    EmployeeServices empService(empRepo);
    EmployeeController empController(empService);
    Router router(empController);

    router.setupRoutes(svr);

    svr.listen("localhost", 9000);

    delete empRepo; // cleanup
    return 0;
}



//g++ main.cpp ./services/EmployeeServices.cpp ./SQL_repository/EmployeeRepository.cpp ./Controller/EmployeeController.cpp ./Router/EmployeeRouter.cpp -o server.exe -D_WIN32_WINNT=0x0A00 -lws2_32 -lwsock32 -I "C:\Program Files\MySQL\MySQL Server 8.0\include" -L "C:\Program Files\MySQL\MySQL Server 8.0\lib" -lmysql