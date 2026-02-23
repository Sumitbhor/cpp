FROM gcc:latest

# Install MySQL/MariaDB development library
RUN apt-get update && apt-get install -y libmariadb-dev

WORKDIR /app

COPY . .

# Compile the project
RUN g++ main.cpp \
    ./services/EmployeeServices.cpp \
    ./SQL_repository/EmployeeRepository.cpp \
    ./Controller/EmployeeController.cpp \
    ./Router/EmployeeRouter.cpp \
    -I/usr/include/mariadb \
    -L/usr/lib/x86_64-linux-gnu \
    -lmariadb \
    -o server

EXPOSE 9000

CMD ["./server"]