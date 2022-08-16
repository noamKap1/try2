#ifndef ASS1_CSVREADER_H
#define ASS1_CSVREADER_H

#include "vector"
#include "string"
#include "Server/Flower.h"

//Read s a csv file and return a data vector which contains the file lines
std::vector<std::vector<std::string>> readFromCSV(const std::string &file);

//Write to a csv file
void writeToCSV(const std::string &file, const std::vector<std::string> &dataVector);

//Calculates the euclidean distance of each flower to the unclassified flower
std::vector<double> lengthArrEuc(std::vector<Flower> data, Flower &unclassified);

//Calculates the chebyshev distance of each flower to the unclassified flower
std::vector<double> lengthArrChev(std::vector<Flower> data, Flower &unclassified);

//Calculates the manhattan distance of each flower to the unclassified flower
std::vector<double> lengthArrMan(std::vector<Flower> data, Flower &unclassified);

//Returns vector which contains all the flower types
std::vector<std::string> typeArr(std::vector<Flower> data);

//Splits the string and puts the cells into the vector
std::vector<std::string> stringSplitterIntoVector(const std::string &, char);

#endif //ASS1_CSVREADER_H