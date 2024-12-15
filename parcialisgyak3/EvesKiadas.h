//
// Created by Balazs on 2024. 12. 15..
//

#ifndef PARCIALISGYAK3_EVESKIADAS_H
#define PARCIALISGYAK3_EVESKIADAS_H
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <utility>
using namespace std;

class EvesKiadas {
private:
    map<string, vector<pair<string, int>>> kiadasok;
public:
    EvesKiadas(const string & filename);
    void listazas() const;
    void ujKiadas(const string& honap, const string& kiadas, int osszeg);
    set<string> kiadasiKategoriak() const;
    double honaponkentiAtlagKiadas(const string& honap) const;
    void kategoriankentiAtlagKiadas(const string&kiadas) const;
};


#endif //PARCIALISGYAK3_EVESKIADAS_H
