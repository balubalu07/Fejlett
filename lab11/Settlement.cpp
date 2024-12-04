//
// Created by Balazs on 2024. 12. 04..
//

#include "Settlement.h"

Settlement::Settlement(string name, string county, int population) {
    this->name = name;
    this->county = county;
    this->population = population;
}

string Settlement::getName() const {
    return this->name;
}

string Settlement::getCounty() const {
    return this->county;
}

int Settlement::getPopulation() const {
    return this->population;
}

void Settlement::setPopulation(int population) {
    this->population = population;

}

void Settlement::setName(string name) {
    this->name=name;

}

void Settlement::setCounty(string county) {
    this->county=county;

}

ostream &operator<<(ostream &os, const Settlement &settlement) {
    os<<"Name: "<<settlement.name<<endl;
    os<<"County: "<<settlement.county<<endl;
    os<<"Population: "<<settlement.population<<endl;
    return os;
}

