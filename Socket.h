#include "string"

#ifndef ASS1_SOCKET_H
#define ASS1_SOCKET_H

class Socket {
public:
    //the size of the buffer
    static const int bufferSize = 4096;

    //gets the message
    virtual std::string stringReceiver() = 0;

    //sends the message
    virtual void stringSender(std::string) = 0;

    //close the socket
    virtual void closer() = 0;

    //destructor
    virtual ~Socket() = default;
};

#endif //ASS1_SOCKET_H
