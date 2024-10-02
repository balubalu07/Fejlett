//
// Created by Balazs on 2024. 10. 02..
//

#ifndef CPP_2024_POINT_H
#define CPP_2024_POINT_H
#include <iostream>
#include <cmath>
#include <set>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <limits>
#include <algorithm>
using namespace std;
class Point {
private:
    int x,y;
public:
    Point(int x=0,int y=0);
    int getX() const;
    int getY() const;
    void print(const string &prefix = "", const string &suffix = "") const;
};

double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
pair<Point, Point> closestPoints(Point* points, int numPoints);
pair<Point, Point> farthestPoints(Point* points, int numPoints);
bool comparePoints(const Point& p1, const Point& p2);
void sortPoints(Point* points, int numPoints);
Point* farthestPointsFromOrigin(Point* points, int numPoints);
void deletePoints(Point* points);





#endif //CPP_2024_POINT_H
