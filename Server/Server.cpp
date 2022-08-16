#include "Server.h"
#include <iostream>
#include <unistd.h>
#include <winsock.h>
#include "stdio.h"
#include "cstring"
#include "../Socket.h"

//Construct a server according to the address and the port
Server::Server(unsigned long address, intptr_t port) : id(socket(AF_INET, SOCK_STREAM, 0)), s() {
    if (id < 0) {
        perror("Error in creating the socket!");
    }
    struct sockaddr_in in;
    memset(&in, 0, sizeof(in));
    in.sin_addr.s_addr = address;
    in.sin_family = AF_INET;
    in.sin_port = port;
    if (bind(id, (struct sockaddr *) &in, sizeof(in)) < 0) {
        perror("Error in binding the socket!");
    }
}

//receives string from the socket
std::string Server::stringReceiver() {
    if (this->cSocket == 0) {
        if (listen(id, this->qLength) < 0) {
            perror("Error in listening to the socket!");
        }
        int len = sizeof(this->s);
        if (accept(id, (struct sockaddr *) &s, &len) < 0) {
            perror("Error in accepting the client!");
        }
        this->cSocket = accept(id, (struct sockaddr *) &s, &len);
    }
    int dataLen = Socket::bufferSize;
    char buff[Socket::bufferSize];
    int bytes = ::recv(this->cSocket, buff, dataLen, 0);
    if (bytes < 0) {
        perror("Error in writing to the socket!");
    }
    std::string res(buff);
    return res;
}

//close the server
void Server::closer() {
    ::close(this->id);
}

//Sends string to the socket
void Server::stringSender(std::string string) {
    int bytes = ::send(this->cSocket, string.c_str(), strlen(string.c_str()), 0);
    if (bytes < 0) {
        perror("Error in sending to the client!");
    }
}