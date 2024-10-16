//
// Created by Balazs on 2024. 10. 16..
//

#ifndef CPP_2024_POINTS_H
#define CPP_2024_POINTS_H
#define M 20
#include <cmath>
using namespace  std;
class Points{
private:
    int x, y;
public:
    Points( int x=0, int y=0);
    int getX() const;
    int getY() const;
    double distanceTo(const Points& point)const ;
};


#endif //CPP_2024_POINTS_H
