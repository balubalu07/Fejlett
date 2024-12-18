//
// Created by Balazs on 2024. 10. 16..
//

#include "Points.h"

Points::Points(int x, int y) {
this->x = x;
this->y = y;
}

int Points::getX() const {
    return this->x;
}

int Points::getY() const {
    return this->y;
}

double Points::distanceTo(const Points &point) const {
    return sqrt(pow(this->x - point.getX(), 2) + pow(this->y - point.getY(), 2));
}
