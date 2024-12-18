//
// Created by Balazs on 2024. 12. 15..
//

#include "Eremtablazat.h"
#include <fstream>
#include <sstream>
Eremtablazat::Eremtablazat(const string &filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string name;
        string medal;
        ss >> name >> medal;
        vector<pair<string,int>> temp;
        temp = this->medalok[name];
        for(int i = 0; i < temp.size(); i++){
            if(temp[i].first == medal){
                temp[i].second++;
                medal ="";
            }
        }
        if(medal != ""){
            temp.push_back(make_pair(medal,1));
        }
        this->medalok[name] = temp;
    }
}

void Eremtablazat::listazas() const {
    for(auto it = this->medalok.begin(); it != this->medalok.end(); it++){
        cout << it->first << ": "<<endl;
        for(int i = 0; i < it->second.size(); i++){
            cout <<"      "<< it->second[i].first << ":" << it->second[i].second << endl;
        }
        cout << endl;
    }
}

void Eremtablazat::ujMedal(const string &nev, const string &medalTipus) {
    vector<pair<string,int>> temp;
    temp = this->medalok[nev];
    bool added=false;

    for(int i=0;i<temp.size();i++){
        if(temp[i].first == medalTipus){
            temp[i].second++;
            added=true;
        }
    }
    if(!added){
        temp.push_back(make_pair(medalTipus,1));
    }
    this->medalok[nev] = temp;
}

set<string> Eremtablazat::sportolok() const {
    set<string> emberek;
    for(auto it = this->medalok.begin(); it != this->medalok.end(); it++){
        emberek.insert(it->first);
    }
    return emberek;
}

int Eremtablazat::medalokSzama(const string &medalTipus) const {
    if(medalTipus!=""){
        int count=0;
        for(auto it = this->medalok.begin(); it != this->medalok.end(); it++){
            for(int i = 0; i < it->second.size(); i++){
                if(it->second[i].first == medalTipus){
                    count++;
                }
            }
        }
        return count;
    }
    else{
        int count=0;
        for(auto it = this->medalok.begin(); it != this->medalok.end(); it++){
            for(int i = 0; i < it->second.size(); i++){

                    count++;

            }
        }
        return count;
    }
}

string Eremtablazat::legtobbMedal() {
    int max=0;
    string maxMedal;
    for(auto it = this->medalok.begin(); it != this->medalok.end(); it++){
        auto it2 = this->medalok.find(it->first);
        int sum=0;
        for(int i = 0; i < it2->second.size(); i++){
            sum+=it2->second[i].second;
        }
        if(sum>max){
            max=sum;
            maxMedal=it->first;
        }
    }
    return maxMedal;
}
