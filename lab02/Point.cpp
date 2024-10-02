//
// Created by Balazs on 2024. 10. 02..
//

#include "Point.h"
Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}

void Point::print(const string &prefix, const string &suffix) const {
    cout<<prefix<<"("<<this->x<<","<<this->y<<")"<<suffix;
}

double distance(const Point &a, const Point &b) {
    double dx =(b.getX()-a.getX())*(b.getX()-a.getX());
    double dy= (b.getY()-a.getY())*(b.getY()-a.getY());
    return sqrt(dx+dy);
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    set<double> set;
    set.insert(distance(a,b));
    set.insert(distance(a,c));
    set.insert(distance(a,d));
    set.insert(distance(b,c));
    set.insert(distance(b,d));
    set.insert(distance(c,d));
    return set.size()==2;

}

void testIsSquare(const char *filename) {
    ifstream f(filename);
    if(!f){
        cout<<"File error";
        return;
    }
        int a,b;
        int roundCount=0;
    while(!f.eof()){
        roundCount++;
        f>>a>>b;
        Point p1(a,b);
        f>>a>>b;
        Point p2(a,b);
        f>>a>>b;
        Point p3(a,b);
        f>>a>>b;
        Point p4(a,b);
        if(isSquare(p1,p2,p3,p4)){
            cout<<roundCount<<". points are in a square!\n";
        }
        else{
            cout<<roundCount<<". points are not in a square!\n";
        }
        }

}

Point *createArray(int numPoints) {
    srand(time(0));
    Point * points = new Point[numPoints];
    int a,b;
    for (int i = 0; i < numPoints; ++i) {
        a = rand() % 2001;
        b = rand() % 2001;
        points[i] = Point(a, b);
    }

    return points;

}

void printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        points[i].print("p","\n");
    }
}

pair<Point, Point> closestPoints(Point *points, int numPoints) {
    double minDistance = numeric_limits<double>::infinity();
    pair<Point, Point> closestPair;
    for (int i = 0; i < numPoints - 1; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double d = distance(points[i], points[j]);
            if (d < minDistance) {
                minDistance = d;
                closestPair = make_pair(points[i], points[j]);
            }
        }
    }
    return closestPair;
}

pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    double minDistance = -1;
    pair<Point, Point> farthestpoints;
    for (int i = 0; i < numPoints - 1; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double d = distance(points[i], points[j]);
            if (d > minDistance) {
                minDistance = d;
                farthestpoints = make_pair(points[i], points[j]);
            }
        }
    }
    return farthestpoints;
}

bool comparePoints(const Point &p1, const Point &p2) {
    return p1.getX() < p2.getX();
}

void sortPoints(Point *points, int numPoints) {
    sort(points, points + numPoints, comparePoints);

    cout << "Rendezett pontok (abszcissza szerint):" << std::endl;
    for (int i = 0; i < numPoints; ++i) {
        points[i].print();
    }
}

Point* farthestPointsFromOrigin(Point* points, int numPoints) {
    static Point farthestPoints[10];
    double distances[10] = { -numeric_limits<double>::infinity() };

    for (int i = 0; i < numPoints; ++i) {
        double distanceSquared = points[i].getX() * points[i].getX() + points[i].getY() * points[i].getY();

        for (int j = 0; j < 10; ++j) {
            if (distanceSquared > distances[j]) {
                for (int k = 9; k > j; --k) {
                    distances[k] = distances[k - 1];
                    farthestPoints[k] = farthestPoints[k - 1];
                }
                distances[j] = distanceSquared;
                farthestPoints[j] = points[i];
                break;
            }
        }
    }

    return farthestPoints;
}
void deletePoints(Point* points) {
    delete[] points;
}
