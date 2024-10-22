#include "Database.h"
#include <fstream>
#include <iostream>
#include <sstream>
void Database::addStudent(Student studentsObject) {
    students.push_back(studentsObject);
    cout << "Student added successfully!" << endl;
}

void Database::displayAllStudents() {
    if (students.size() == 0) { 
        cout << "No students in the database." << endl;
        return;
    }
    for (Student studentsObject : students) {
        studentsObject.displayStudent();
        cout << "---------------------" << endl;
    }
}

void Database::deleteStudent(int roll) {
   
    auto it = std::remove_if(students.begin(), students.end(),
        [roll](const Student& student) { return student.getRollNumber() == roll; });

    if (it != students.end()) {
        students.erase(it, students.end()); 
        cout << "Student with roll number " << roll << " deleted." << endl;
    }
    else {
        cout << "Student with roll number " << roll << " not found." << endl;
    }

    saveToFile("StudentsDB/students.txt");
}
Student* Database::searchStudentByRoll(int roll) {
    for (Student& studentsObject : students) {
        if (studentsObject.getRollNumber() == roll) {
            return &studentsObject;
        }
    }
    cout << "Student not found!" << endl;
    return nullptr;
}

Student* Database::searchStudentByName(const string& name) {
    for (Student& studentsObject : students) {
        if (studentsObject.getName() == name) {
            return &studentsObject;
        }
    }
    cout << "Student not found!" << endl;
    return nullptr;
}
void Database::saveToFile(const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const Student& studentsObject : students) {
            outFile << studentsObject.getRollNumber() << ","
                << studentsObject.getName() << ","
                << studentsObject.getCourse() << ","
                << studentsObject.getGrade() << endl;
        }
        outFile.close(); 
        cout << "Data saved to " << filename << endl;
    }
    else {
        cout << "Error opening file for writing!" << endl;
    }
}


void Database::loadFromFile(const string& filename) {
    ifstream inFile(filename); 
    if (inFile.is_open()) {
        students.clear(); 
        string line;
        while (getline(inFile, line)) {
            stringstream textToWrite(line);
            string rollStr, name, course, gradeStr;

            getline(textToWrite, rollStr, ',');
            getline(textToWrite, name, ',');
            getline(textToWrite, course, ',');
            getline(textToWrite, gradeStr, ',');

            int roll = stoi(rollStr); 
            float grade = stof(gradeStr);

            Student studentsObject(roll, name, course, grade);
            students.push_back(studentsObject);
        }
        inFile.close(); 
        cout << "Data loaded from " << filename << endl;
    }
    else {
        cout << "There is no file or an Error opening file for reading!" << endl;
    }
}
