
//must go BEFORE httplib

#include "httplib.h"
#include "./SQL_repository/EmployeeRepository.h"
#include "./services/EmployeeServices.h"
#include "./Controller/EmployeeController.h"
#include "./Router/EmployeeRouter.h"

using namespace httplib;

int main() {
    Server svr;

    // Enable CORS
    svr.set_default_headers({
        {"Access-Control-Allow-Origin", "*"},
        {"Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS"},
        {"Access-Control-Allow-Headers", "Content-Type"}
    });

    svr.Options(".*", [](const Request&, Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");
        res.status = 204;
    });

    svr.set_mount_point("/", "./public");

    IEmployeeRepository* empRepo = new EmployeeRepository();
    EmployeeServices empService(empRepo);
    EmployeeController empController(empService);
    Router router(empController);

    router.setupRoutes(svr);
svr.listen("0.0.0.0", 9000);
 

    delete empRepo; // cleanup
    return 0;
}


//https://localhost:9000/api/Employees
/*g++ main.cpp \
./services/EmployeeServices.cpp \
./SQL_repository/EmployeeRepository.cpp \
./Controller/EmployeeController.cpp \
./Router/EmployeeRouter.cpp \
-o server \
-lmysqlclient*/
