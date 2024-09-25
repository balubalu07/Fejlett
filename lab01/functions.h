//
// Created by Balazs on 2024. 09. 25..
//

#ifndef CPP_2024_FUNCTIONS_H
#define CPP_2024_FUNCTIONS_H
#include <utility>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;
int countBits(int number);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
pair<double, double> max2(double array[], int numElements);
int countWords(string text);
string code(string text);
string decode(string text);
string capitalizeWords(string text);

#endif //CPP_2024_FUNCTIONS_H
