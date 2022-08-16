#include "Socket.h"
#include <winsock.h>
#include "string"
#include "../Socket.h"

#ifndef ASS1_SERVER_H
#define ASS1_SERVER_H

class Server : public Socket {
private:
    int id;
    int qLength = 5;
    struct sockaddr_in s;
    int cSocket = 0;
public:
    //Construct a server according to the address and the port
    Server(unsigned long address, intptr_t port);

    //Sends string to the socket
    void stringSender(std::string string) override;

    //receives string from the socket
    std::string stringReceiver() override;

    //close the server
    void closer() override;

    //destructor
    ~Server() override = default;
};

#endif //ASS1_SERVER_H
