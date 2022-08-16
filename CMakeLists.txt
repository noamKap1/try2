cmake_minimum_required(VERSION 3.20)
project(ass1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server server/main.cpp server/Classifier.h server/Classifiable.h server/Flower.cpp
        server/Flower.h server/Server.cpp server/Server.h CsvReader.h CsvReader.cpp
        Socket.h)
add_executable(Client client/main.cpp client/Client.cpp client/Client.h CsvReader.h CsvReader.cpp
        Socket.h)
