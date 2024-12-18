//
// Created by Balazs on 2024. 11. 27..
//

#include "GraduationDao.h"
#include <fstream>
void GraduationDao::enrollStudents(const string &filename) {
    ifstream f(filename);
    if(!f){
        cout<<"File error\n";
        return;
    }
    string firstName,lastName;
    int id;
    while(f>>id>>firstName>>lastName){
        Student student(id,firstName,lastName);
        this->students.insert({id,student});
    }
}

void GraduationDao::readGradesSubject(const string &subject, const string &filename) {
    ifstream f(filename);
    if(!f){
        cout<<"File error\n";
        return;
    }
    int id;
    double grade;
    while(f>>id>>grade){
        this->students.at(id).addGrade(subject,grade);
    }
}

void GraduationDao::computeAverage() {
    for(auto &[key,value]:this->students){
        value.computeAverage();
    }
}

int GraduationDao::numEnrolled() const {
    return this->students.size();
}

int GraduationDao::numPassed() const {
    int count=0;
    for(auto &[key,value]:this->students){
        if(value.getAverage()>=6.0){
            count++;
        }
    }
    return count;
}

Student GraduationDao::findById(int id) const {
    if(this->students.find(id)==this->students.end()){
        throw out_of_range("No such id");
    }
    return this->students.at(id);
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double sum=0.0;
    for(auto &[key,value]:this->students){
        sum+=value.getGrade(subject);
    }
    return sum/this->students.size();
}
