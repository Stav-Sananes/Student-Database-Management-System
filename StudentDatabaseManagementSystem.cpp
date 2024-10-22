#include "Database.h"
#include <iostream>
#include <filesystem>

using namespace std;
void clearInputStream() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
template <typename T>
T getValidInput(const string& prompt, const string& errorMsg) {
    T input;
    while (true) {
        cout << prompt;
        cin >> input;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input; 
        }
        else {
            cout << errorMsg << endl; 
            clearInputStream();
        }
    }
}

int main() {
    Database db;
    string directory = "StudentDB"; 
    string filename = directory + "/students.txt"; 

    if (!filesystem::exists(directory)) {
        filesystem::create_directory(directory);
        cout << "Created directory: " << directory << endl;
    }
    else {
        cout << "Directory already exists: " << directory << endl;
    }

    db.loadFromFile(filename);
    int choice;
    do {
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Search Student by Roll Number" << endl;
        cout << "5. Search Student by Name" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
     

        if (choice == 1) {
            int roll = getValidInput<int>("Enter roll number: ", "Invalid input for roll number! Please enter a valid number.");
            string name, course;
            cout << "Enter roll number: ";
            cin >> roll;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter course: ";
            getline(cin, course);
            float grade = getValidInput<float>("Enter grade: ", "Invalid input for grade! Please enter a valid number.");
            Student saveStudent(roll, name, course, grade);
            db.addStudent(saveStudent);
            db.saveToFile(filename); 
        }
        else if (choice == 2) {
            db.displayAllStudents();
        }
        else if (choice == 3) {
            int roll = getValidInput<int>("Enter roll number: ", "Invalid input for roll number! Please enter a valid number.");
            db.deleteStudent(roll);
        }
        else if (choice == 4) {
            int roll = getValidInput<int>("Enter roll number to search: ", "Invalid input for roll number! Please enter a valid number.");
            Student* student = db.searchStudentByRoll(roll);
            if (student != nullptr) {
                student->displayStudent();
            }
        }
        else if (choice == 5) {
            string name;
            cout << "Enter name to search: ";
            cin.ignore();
            getline(cin, name);
            Student* student = db.searchStudentByName(name);
            if (student != nullptr) {
                student->displayStudent();
            }
        }
        else if (choice == 6) {
            cout << "Exiting system. Goodbye!" << endl;
            break;
        }
        else if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid choice." << endl;
            continue; 
        }

    } while (choice != 6);

    db.saveToFile(filename);
    return 0;
}
