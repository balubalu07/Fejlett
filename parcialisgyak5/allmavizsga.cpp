//
// Created by Balazs on 2024. 12. 17..
//

#include "allmavizsga.h"
#include <fstream>
#include <iostream>
#include <sstream>
allmavizsga::allmavizsga(const string &filename) {
    ifstream  f(filename);
    string line;
    while(getline(f,line)){
        string name;
        name = line.substr(0,line.find(':'));
        line = line.substr(line.find('[')+1,line.find(']')-line.find('[')-1);
        stringstream  ss(line);
        string keyword;
        while(getline(ss,keyword,',')){
            keyword = keyword.substr(2,keyword.length()-3);
            vector<string> temp = allamvizsgak[keyword];
            temp.push_back(name);
            allamvizsgak[keyword] = temp;
        }
    }
}

void allmavizsga::display() {
    for(auto it = allamvizsgak.begin(); it != allamvizsgak.end(); it++){
        cout << it->first << ": ";
        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
            cout << *it2 << ", ";
        }
        cout << endl;
    }
}

vector<string> allmavizsga::searchKeyword(const string &keyword) {
    return allamvizsgak[keyword];
}

map<string,vector<string>> allmavizsga::search(const string &search) {
    map<string,vector<string>> result;
    for(auto it = allamvizsgak.begin(); it != allamvizsgak.end(); it++){
        string words;
        stringstream ss(it->first);
        while(getline(ss,words)){
            if(words.find(search) != string::npos){
                vector<string> temp= allamvizsgak[words];
                result[words] = temp;
            }
        }
    }
    return result;
}
