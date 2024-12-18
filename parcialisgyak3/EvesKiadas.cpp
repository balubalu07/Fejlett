//
// Created by Balazs on 2024. 12. 15..
//

#include "EvesKiadas.h"
#include <fstream>
#include <sstream>
#include <iostream>
using  namespace std;
EvesKiadas::EvesKiadas(const string &filename) {
    ifstream file(filename);
    string line;
    while(getline(file, line)){
        istringstream ss(line);
        string month;
        string category;
        int amount;
        ss >> month >> category >> amount;
        vector<pair<string,int>> temp;
        temp = this->kiadasok[month];
        temp.push_back(make_pair(category,amount));
        this->kiadasok[month] = temp;
    }
}

void EvesKiadas::listazas() const {
    for(auto it = this->kiadasok.begin(); it != this->kiadasok.end(); ++it){
        cout << it->first<< endl;
        for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2){
            cout << "    " << it2->first << ":" << it2->second << endl;
        }
    }
}

void EvesKiadas::ujKiadas(const string &honap, const string &kiadas, int osszeg) {
    vector<pair<string,int>> temp;
    temp = this->kiadasok[honap];
    temp.push_back(make_pair(kiadas,osszeg));
    this->kiadasok[honap] = temp;
}

set<string> EvesKiadas::kiadasiKategoriak() const {
    set<string> temp;
    for(auto it = this->kiadasok.begin(); it != this->kiadasok.end(); ++it){
        for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2){
            temp.insert(it2->first);
        }
    }
    return temp;
}

double EvesKiadas::honaponkentiAtlagKiadas(const string &honap) const {
    double osszeg=0;
    auto it = this->kiadasok.find(honap);
    if(it== this->kiadasok.end()){
        return 0.0;
    }
    const auto& temp = it->second;
    if(temp.empty()){
        return 0.0;
    }
    for(const auto& kiadasok:temp){
        osszeg += kiadasok.second;
    }
    return osszeg/temp.size();
}

void EvesKiadas::kategoriankentiAtlagKiadas(const string&kiadas) const {
    for(auto it = this->kiadasok.begin(); it != this->kiadasok.end(); ++it){
        cout << it->first<< endl;
        for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2){
           if(it2->first == kiadas){
               cout<< "    " << it2->first << ":" << it2->second<<endl;
           }
        }
    }
}
