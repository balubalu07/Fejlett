//
// Created by Balazs on 2024. 12. 11..
//

#ifndef LAB12_SIMPLETEXTGENERATOR_H
#define LAB12_SIMPLETEXTGENERATOR_H
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
class SimpleTextGenerator {
    map<string, vector<string>> data;
public:
    virtual void trainFromText(string trainingText);
    virtual void trainFromFile(string filename);
    virtual string generate(string startWords, int numWords=6);
    void printData() const; // a map kiíratása
};


#endif //LAB12_SIMPLETEXTGENERATOR_H
