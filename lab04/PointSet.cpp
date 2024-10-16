//
// Created by Balazs on 2024. 10. 16..
//

#include "PointSet.h"
bool used[M+1][M+1]{false};

PointSet::PointSet(int n) {
    this->n=n;
    this->points.reserve(n);
    while(points.size() < n){
        int x = rand() % M + 1;
        int y = rand() % M + 1;
        if(!used[x][y]){
            used[x][y]=true;
            points.push_back({x,y});
        }
    }
    PointSet::computeDistances();
    PointSet::exportPoints("points.csv");
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(),distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for (int i = 0; i < n; ++i) {
        cout << points[i].getX() << " " << points[i].getY() << endl;
    }
}

void PointSet::printDistances() const {
    for (int i = 0; i < n; ++i) {
        cout << distances[i] << endl;
    }
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), [](Points a, Points b){return a.getX() < b.getX();});
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), [](Points a, Points b){return a.getY() < b.getY();});
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    return unique(distances.begin(), distances.end()) - distances.begin();
}

void PointSet::computeDistances() {
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j <n ; ++j) {
            distances.push_back(points[i].distanceTo( points[j]));
        }
    }
}

void PointSet::exportPoints(const string &filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& point : points) {
            file << point.getX() << "," << point.getY() << "\n"; // Export in CSV format
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}


