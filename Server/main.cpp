#include <vector>
#include "Flower.h"
#include "Classifier.h"
#include "Server.h"
#include "Classifier.h"
#include "../CsvReader.h"
#include "../Socket.h"

int main(int argc, char *argv[]) {
    std::vector<Flower> classified = flowersVector(readFromCSV(argv[1]));
    Classifier<Flower> classifier(classified, 5);
    Socket *sServer;
    sServer = new Server(INADDR_ANY, htons(55555));
    std::string message = sServer->stringReceiver();
    std::vector<std::string> v = stringSplitterIntoVector(message, '\n');
    std::string string;
    for (const std::string &index: v) {
        Flower flower(index);
        string.append(classifier.classify(flower, classifier.getDataVector(),
                                          lengthArrEuc(classifier.getDataVector(),
                                                      flower),
                                          typeArr(classifier.getDataVector())));
        string.append("\n");
    }
    sServer->stringSender(string);
    sServer->closer();
    delete sServer;
    return 0;
}
