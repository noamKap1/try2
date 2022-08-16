#include <string>
#include <cstring>
#include <unistd.h>
#include "Client.h"

//Construct a Client according to the address and the port
Client::Client(unsigned long address, intptr_t port) : cSocket(socket(AF_INET, SOCK_STREAM, 0)), s() {
    if (cSocket < 0) {
        perror("Error in creating the socket!");
    }
    memset(&s, 0, sizeof(s));
    s.sin_port = port;
    s.sin_addr.s_addr = address;
    s.sin_family = AF_INET;
}

//Sends string to the socket
void Client::stringSender(std::string str) {
    if (connected == false) {
        if (connect(cSocket, (struct sockaddr *) &s, sizeof(s)) < 0) {
            perror("Error connecting to the server!");
        }
        connected = true;
    }
    int bytes = ::send(cSocket, str.c_str(), strlen(str.c_str()), 0);
    if (bytes < 0) {
        perror("Error writing to the socket!");
    }
}

//receives string from the socket
std::string Client::stringReceiver() {
    char buff[Socket::bufferSize];
    int bytes = ::recv(cSocket, buff, Socket::bufferSize, 0);
    if (bytes < 0) {
        perror("Error reading s the socket!");
    }
    std::string message(buff, strlen(buff));
    return message;
}

//close the client
void Client::closer() {
    ::close(this->cSocket);
}

