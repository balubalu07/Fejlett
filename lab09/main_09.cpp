#include <iostream>
#include "Student.h"
#include "GraduationDao.h"
int main() {
    string subjects[]{"math", "romanian", "hungarian"};
    int numSubjects = sizeof(subjects) / sizeof(subjects[0]);
    Student s1 = Student(1, "Balazs", "Bence");
//    cout<<s1;
    GraduationDao d1 = GraduationDao(2024);
    d1.enrollStudents("names.txt");
    cout<<"Number of students: "<<d1.numEnrolled()<<endl;
    for (int i = 0; i < numSubjects; ++i) {
        d1.readGradesSubject(subjects[i], subjects[i] + ".txt");
    }
    d1.computeAverage();
    cout <<"Number of passed students: " << d1.numPassed() << endl;



    return 0;
}