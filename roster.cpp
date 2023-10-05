#include <regex>
#include "roster.h"
#include <iostream>

// Constructor
Roster::Roster() {
    for (int i = 0; i < numStudents; i++) {
        this->classRosterArray[i] = nullptr;
    }
}

// Destructor
Roster::~Roster() {
    for (int i = 0; i < numStudents; i++) {
        delete this->classRosterArray[i];
        this->classRosterArray[i] = nullptr;
    }
}
Student** Roster::GetRosterArray() {
    return classRosterArray;
}
// add() method
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysToComplete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);
            break;
        }
    }
}

// remove() method
void Roster::remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i < numStudents; i++) {
        if (this->classRosterArray[i] != nullptr && this->classRosterArray[i]->GetStudentID() == studentID) {
            found = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = nullptr;
            std::cout << "Student with ID: " << studentID << " has been removed from the roster." << std::endl;
        }
    }
    if (!found) {
        std::cout << "Student with ID: " << studentID << " not found." << std::endl;
    }
}

// printAll() method
void Roster::printAll() {
    for (int i = 0; i < numStudents; i++) {
        if (this->classRosterArray[i] != nullptr) {
            this->classRosterArray[i]->Print();
        }
    }
}

// printAverageDaysInCourse() method
void Roster::printAverageDaysInCourse(std::string studentID) {
    bool found = false;
    for (int i = 0; i < numStudents; i++) {
        if (this->classRosterArray[i] != nullptr && this->classRosterArray[i]->GetStudentID() == studentID) {
            found = true;
            int* days = this->classRosterArray[i]->GetDaysToComplete();
            std::cout << "Average days in course for " << studentID << ": " << (days[0] + days[1] + days[2]) / 3 << std::endl;
        }
    }
    if (!found) {
        std::cout << "Student with ID: " << studentID << " not found." << std::endl;
    }
}

// printInvalidEmails() method
void Roster::printInvalidEmails() {
    std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    for (int i = 0; i < numStudents; i++) {
        if (this->classRosterArray[i] != nullptr) {
            std::string email = this->classRosterArray[i]->GetEmailAddress();
            if (!std::regex_match(email, pattern)) {
                std::cout << "Invalid email for student ID " << this->classRosterArray[i]->GetStudentID() << ": " << email << std::endl;
            }
        }
    }
}

// printByDegreeProgram() method
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < numStudents; i++) {
        if (this->classRosterArray[i] != nullptr && this->classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            this->classRosterArray[i]->Print();
        }
    }
}
