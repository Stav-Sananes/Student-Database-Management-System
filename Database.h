#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include "Student.h"
#include <vector>
#include <string>

class Database {
private:
    vector<Student> students;

public:
    void addStudent(Student s);
    void displayAllStudents();
    void deleteStudent(int roll);
    Student* searchStudentByRoll(int roll); 
    Student* searchStudentByName(const std::string& name);
    void saveToFile(const std::string& filename); // Save to file
    void loadFromFile(const std::string& filename); // Load from file

};

#endif
