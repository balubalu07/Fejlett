//
// Created by Balazs on 2024. 10. 16..
//

#ifndef CPP_2024_POINTSET_H
#define CPP_2024_POINTSET_H
#include "Points.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;


class PointSet {
    vector<Points> points;
    int n;
    vector<double> distances;
    void computeDistances();
    void exportPoints(const string &filename) const;
public:
    PointSet( int n = 100 );
//maximum kiválasztás a tavolsag tömbből
    double maxDistance() const;
//minimum kiválasztás a tavolsag tömbből
    double minDistance() const;
//összesen hány távolság értelmezhető n
//különböző pont között
    int numDistances() const;
//a pontok tároló kiíratása
    void printPoints() const;
//a tavolsagok tároló kiíratása
    void printDistances() const;
//növekvő sorrendbe rendezi a pontokat x koordináta szerint
    void sortPointsX();
//u. a. y koordináta szerint
    void sortPointsY();
//a tavolsagok tároló rendezése
    void sortDistances();
//hány darab különböző távolságot tartalmaz a tavolsagok tömb
    int numDistinctDistances();

};


#endif //CPP_2024_POINTSET_H
