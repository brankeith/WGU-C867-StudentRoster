#pragma once
#include <string>
#include "degree.h"
#include "student.h"
using std::string;

class Roster {
public:
    void Add(const string studentID, const string firstName, const string lastName, const string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void Remove(const string studentID);
    void PrintAll() const;
    void PrintAverageDaysInCourse(const string studentID) const;
    void PrintInvalidEmails() const;
    void PrintByDegreeProgram(DegreeProgram degreeProgram) const;

    // Destructor
    ~Roster();

private:
    static const int kMaxStudents = 5;
    int lastIndex;
    Student* classRosterArray[kMaxStudents];
};
