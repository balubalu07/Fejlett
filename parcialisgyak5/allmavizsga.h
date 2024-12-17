//
// Created by Balazs on 2024. 12. 17..
//

#ifndef PARCIALISGYAK5_ALLMAVIZSGA_H
#define PARCIALISGYAK5_ALLMAVIZSGA_H
#include <map>
#include <string>
#include <vector>
using namespace std;

class allmavizsga {
private:
    map<string,vector<string>> allamvizsgak;
public:
    allmavizsga(const string& filename);
    void display();
    vector<string> searchKeyword(const string& keyword);
    map<string,vector<string>> search(const string& search);
};


#endif //PARCIALISGYAK5_ALLMAVIZSGA_H
