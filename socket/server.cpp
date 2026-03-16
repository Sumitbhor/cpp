#include <iostream>
#include <winsock2.h>

using namespace std;

#pragma comment(lib, "ws2_32.lib")   // Link library

int main() {

    WSADATA wsa;
    SOCKET serverSocket, clientSocket;

    // Initialize Winsock
    WSAStartup(MAKEWORD(2,2), &wsa);

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind
    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));

    // Listen
    listen(serverSocket, 3);

    cout << "Server started...\n";

    // Accept
    clientSocket = accept(serverSocket, NULL, NULL);

    char buffer[1024];

    // Receive
    recv(clientSocket, buffer, sizeof(buffer), 0);

    cout << "Client: " << buffer << endl;

    // Send
    send(clientSocket, "Hello from Server", 17, 0);

    // Close
    closesocket(clientSocket);
    closesocket(serverSocket);

    WSACleanup();

    return 0;
}
