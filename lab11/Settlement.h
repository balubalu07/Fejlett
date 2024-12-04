//
// Created by Balazs on 2024. 12. 04..
//

#ifndef LAB11_SETTLEMENT_H
#define LAB11_SETTLEMENT_H
#include <string>
#include <iostream>

using namespace std;
class Settlement {
    string name = "";
    string county = "";
    int population = 0;
public:
    Settlement(string name, string county, int population);
    string getName() const;
    string getCounty() const;
    int getPopulation() const;
    void setPopulation(int population);
    void setName(string name);
    void setCounty(string county);
    friend ostream& operator<<(ostream& os, const Settlement& settlement);
};


#endif //LAB11_SETTLEMENT_H
