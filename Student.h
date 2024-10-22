#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    string course;
    float grade;

public:
    Student(int roll, string n, string c, float g);

    int getRollNumber() const;
    string getName() const;
    void displayStudent();
    string getCourse() const;
    float getGrade() const;
};

#endif
