#include <iostream>
#include "Point.h"
using namespace std;
int main(int argc, char** argv) {
//    Point p1(2,3);
//    p1.print("p1","\n");
//    Point p2(100, 200);
//    p2.print("p2","\n");
//    Point * pp1 = new Point(300, 400);
//    Point * pp2 = new Point(500, 1000);
//    pp1->print("pp1","\n");
//    pp2->print("pp2","\n");
//    cout<<"distance between p1 and p2:"<<distance(p1,p2)<<endl;
//    cout<<"distance between pp1 and pp2:"<<distance(pp1,pp2)<<endl;
//    if(isSquare(p1,p2,*pp1,*pp2)){
//        cout<<"square"<<endl;
//    }
//    else{
//        cout<<"not square"<<endl;
//    }
//    testIsSquare("points.txt");
    int N;
    cout<<"give me the number of points:";
    cin>>N;
    Point * points =createArray(N);
    printArray(points,N);
    pair<Point,Point> result = closestPoints(points,N);
    cout<<"closest points"<<endl;
    result.first.print("p1","\n");
    result.second.print("p2","\n");
    result = farthestPoints(points,N);
    cout<<"farthest points"<<endl;
    result.first.print("p1","\n");
    result.second.print("p2","\n");
//    sortPoints(points,N);
//    Point* farthest = farthestPointsFromOrigin(points, N);
//    cout<<"\nfarthest point from origin:\n";
//    for (int i = 0; i < 10; ++i) {
//        farthest[i].print("p","\n");
//    }
//    deletePoints(points);

//    delete pp1;
//    delete pp2;

    return 0;
}
