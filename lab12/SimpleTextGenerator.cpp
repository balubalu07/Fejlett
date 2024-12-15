//
// Created by Balazs on 2024. 12. 11..
//

#include "SimpleTextGenerator.h"
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <fstream>
void SimpleTextGenerator::trainFromText(string trainingText) {
    istringstream stream(trainingText);
    string word;
    vector<string> helper;
    while (stream >> word) {
        word.erase(word.begin(), std::find_if(word.begin(), word.end(), ::isalnum));
        word.erase(find_if(word.rbegin(), word.rend(), ::isalnum).base(), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        helper.push_back(word);
    }
    for(int i=0;i<helper.size()-1;i++){
           if(data.find(helper[i]+" "+helper[i+1]) != data.end()){
               vector<string>& values = data[helper[i]+" "+helper[i+1]];
               if(find(values.begin(),values.end(),helper[i+2]) == values.end()){
                   values.push_back(helper[i+2]);
               }
           }
           else{
               data[helper[i]+" "+helper[i+1]] = {helper[i+2]};
           }
    }
}

void SimpleTextGenerator::trainFromFile(string filename) {
    ifstream f(filename);
    if (!f) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(f, line)) {
        istringstream stream(line);
        string word;
        vector<string> helper;

        while (stream >> word) {
            word.erase(word.begin(), find_if(word.begin(), word.end(), ::isalnum));
            word.erase(find_if(word.rbegin(), word.rend(), ::isalnum).base(), word.end());
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (!word.empty()) {
                helper.push_back(word);
            }
        }

        if (helper.size() < 3) {
            continue;
        }

        for (size_t i = 0; i < helper.size() - 2; i++) {
            string bigram = helper[i] + " " + helper[i + 1];

            if (data.find(bigram) != data.end()) {
                vector<string>& values = data[bigram];
                if (find(values.begin(), values.end(), helper[i + 2]) == values.end()) {
                    values.push_back(helper[i + 2]);
                }
            } else {
                data[bigram] = {helper[i + 2]};
            }
        }
    }
}

string SimpleTextGenerator::generate(string startWords, int numWords) {
    vector<string> helper = data[startWords];
    vector<string>result;
    istringstream stream(startWords);
    srand(time(0));
    string word;
    while(stream>>word){
        result.push_back(word);
    }
    if(helper.size()>0){
        result.push_back(helper[rand() % helper.size()]);
    }
    for(int i=0;i<numWords-1;i++){
        helper = data[result[result.size()-2]+" "+result[result.size()-1]];
        if(helper.size()>0){
            result.push_back(helper[rand() % helper.size()]);
        }
    }
    string res;
    for(auto e:result){
        res=res+" "+e;
    }
    return res;
}

void SimpleTextGenerator::printData() const {
    for(const auto& [key,value]:data){
        cout<<key<<": ";
        for (const auto& w:value) {
            cout<<w<<",";
        }
        cout<<endl;
    }
}
