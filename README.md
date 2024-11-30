# TCP-Chat-Application
A TCP Chat Application is a network-based program that enables real-time communication between multiple users over the Transmission Control Protocol (TCP). The application typically consists of two main components: the server and the client.

Key Features:

Server:
Acts as the central hub for communication.
Listens for incoming client connections on a specific IP address and port.
Handles multiple clients concurrently using multithreading.
Broadcasts messages received from one client to all connected clients.

Client:
Connects to the server using its IP address and port.
Allows users to send messages to the server.
Receives messages broadcast by the server from other connected clients.
Provides a simple user interface (text-based or graphical) for interaction.


How It Works:

Connection Establishment:
The server starts by creating a socket, binding it to a specific port, and listening for incoming connections.
Clients connect to the server using its IP and port number.

Message Exchange:
Once connected, the client and server communicate using TCP, which ensures reliable delivery of messages.
Messages sent by one client are forwarded by the server to all other connected clients.

Concurrency:
The server handles multiple clients simultaneously by creating a separate thread or process for each connected client.
This ensures smooth communication without blocking the server or other clients.

Disconnection Handling:
The server detects when a client disconnects and removes them from the active connections list.

Technologies and Tools:
Programming Languages: C language with socket programming support.

Libraries/Frameworks:
C: <sys/socket.h> (Linux), <winsock2.h> (Windows)

Network Protocol: TCP/IP for reliable communication.
Potential Enhancements:
Authentication: Add login functionality for secure access.
Encryption: Secure messages using encryption protocols like SSL/TLS.
GUI: Develop a graphical user interface for improved user experience.
File Sharing: Allow users to send files along with text messages.
This project is ideal for learning about socket programming, multithreading, and real-time networking concepts.

O/P : 

![Screenshot](https://github.com/CosmicViraj/TCP-Chat-Application/blob/main/bin/Screenshot_output.jpg
)

 
