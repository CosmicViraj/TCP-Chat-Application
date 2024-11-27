#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib") // Link with ws2_32.lib

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE], message[BUFFER_SIZE];

    // Initialize Winsock
    printf("Initializing Winsock...\n");
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Initialized.\n");

    // Create a socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Socket created.\n");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(SERVER_IP);
    server.sin_port = htons(PORT);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Connected to server.\n");

    // Communicate with the server
    while (1) {
        printf("Enter message: ");
        fgets(message, BUFFER_SIZE, stdin);

        // Send message to server
        send(client_socket, message, strlen(message), 0);

        // Receive reply from server
        memset(buffer, 0, BUFFER_SIZE);
        int recv_size = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (recv_size == SOCKET_ERROR) {
            printf("Recv failed. Error Code: %d\n", WSAGetLastError());
            break;
        }

        printf("Server: %s\n", buffer);
    }

    // Cleanup
    closesocket(client_socket);
    WSACleanup();

    return 0;
}

