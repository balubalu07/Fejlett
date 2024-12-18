//
// Created by Balazs on 2024. 11. 27..
//

#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
}

int Student::getId() const {
    return  this->id;
}

void Student::setId(int id) {
    this->id = id;
}

const string &Student::getFirstName() const {
    return this->firstName;
}

const string &Student::getLastName() const {
    return this->lastName;
}

void Student::addGrade(const string &subject, double grade) {
    this->grades[subject] = grade;
}

double Student::getGrade(const string &subject) const {
    if(subject !="math" || subject != "hungarian" || subject != "romanian") throw out_of_range("Subject not found");
    return this->grades.at(subject);
}

const map<string, double> &Student::getGrades() const {
    return this->grades;
}

void Student::computeAverage() {
    double sum = 0;
    for (auto&[key,value] : this->grades) {
        if(value <5.0) return;
        sum += value;
    }
    if(sum/3>=6.0){
        this->average = sum / this->grades.size();
    };
}

double Student::getAverage() const{
    return this->average;
}

ostream &operator<<(ostream &os, const Student &student) {
    os<<"ID: "<<student.id<<endl;
    os<<"Nev: "<<student.firstName<<" "<<student.lastName<<endl;
    os<<"Atlag: "<<student.average<<endl;
    return os;
}
