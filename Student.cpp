#include "Student.h"
#include <iostream>

Student::Student(int roll, string n, string c, float g) {
    rollNumber = roll;
    name = n;
    course = c;
    grade = g;
}

int Student::getRollNumber() const {
    return rollNumber;
}

string Student::getName() const {
    return name;
}
string Student::getCourse() const {
    return course;
}
float Student::getGrade() const {
    return grade;
}
void Student::displayStudent() {
    cout << "Roll Number: " << rollNumber << endl;
    cout << "Name: " << name << endl;
    cout << "Course: " << course << endl;
    cout << "Grade: " << grade << endl;
}
