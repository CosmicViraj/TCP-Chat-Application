#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib") 

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server, client;
    int client_len;
    char buffer[BUFFER_SIZE];

    // Initialize Winsock
    printf("Initializing Winsock...\n");
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Initialized.\n");

    // Create a socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Socket created.\n");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    if (bind(server_socket, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        printf("Bind failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Bind done.\n");

    // Listen
    listen(server_socket, 3);
    printf("Waiting for incoming connections...\n");

    client_len = sizeof(struct sockaddr_in);

    // Accept a connection
    client_socket = accept(server_socket, (struct sockaddr *)&client, &client_len);
    if (client_socket == INVALID_SOCKET) {
        printf("Accept failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Connection accepted.\n");

    // Communicate with the client
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);

        // Receive a message
        int recv_size = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (recv_size == SOCKET_ERROR) {
            printf("Recv failed. Error Code: %d\n", WSAGetLastError());
            break;
        }

        printf("Client: %s\n", buffer);

        // Echo message back to client
        send(client_socket, buffer, strlen(buffer), 0);
    }

    // Cleanup
    closesocket(server_socket);
    closesocket(client_socket);
    WSACleanup();

    return 0;
}

