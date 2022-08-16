#ifndef ASS1_CLIENT_H
#define ASS1_CLIENT_H

#include <winsock.h>
#include "string"
#include "../Socket.h"

class Client : public Socket {
private:
    int cSocket;
    bool connected = false;
    struct sockaddr_in s;
public:
    //receives string from the socket
    std::string stringReceiver() override;

    //Sends string to the socket
    void stringSender(std::string) override;

    //close the client
    void closer() override;

    //Construct a Client according to the address and the port
    Client(unsigned long, intptr_t);

    //destructor
    ~Client() override = default;
};

#endif //ASS1_CLIENT_H
