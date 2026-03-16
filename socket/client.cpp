#include <iostream>
#include <winsock2.h>

using namespace std;

#pragma comment(lib, "ws2_32.lib")

int main() {

    WSADATA wsa;
    SOCKET sock;

    WSAStartup(MAKEWORD(2,2), &wsa);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);

    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect
    connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr));

    // Send
    send(sock, "Hello Server", 12, 0);

    char buffer[1024];

    // Receive
    recv(sock, buffer, sizeof(buffer), 0);

    cout << "Server: " << buffer << endl;

    closesocket(sock);

    WSACleanup();

    return 0;
}
