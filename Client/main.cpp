#include <iostream>
#include "vector"
#include "../CsvReader.h"
#include "../Socket.h"
#include "Client.h"
#include <winsock.h>

int main(int argc, char *argv[]) {
    //creates the client according to how we learned
    Client client(inet_addr("127.0.0.1"), htons(55555));
    std::string string;
    std::getline(std::cin, string);
    std::vector<std::string> filesString = stringSplitterIntoVector(string, ' ');
    std::vector<std::vector<std::string>> unclassified = readFromCSV(filesString[0]);
    Socket *sClient = &client;
    std::string message;
    for (const std::vector<std::string> &i: unclassified) {
        for (const std::string &j: i) {
            message.append(j);
            message.append(" ");
        }
        message.pop_back();
        message.append("\n");
    }
    message.pop_back();
    sClient->stringSender(message);
    std::string types = sClient->stringReceiver();
    writeToCSV(filesString[1], stringSplitterIntoVector(types, '\n'));
    client.closer();
    return 0;
}