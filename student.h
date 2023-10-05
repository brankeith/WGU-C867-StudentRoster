#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student {
public:

    //getturs
    string GetstudentID();
    string getfirstName();
    string getLastName();
    string GetEmailAddress();
    int GetAge();
    int* GetDaysCompleted();
    DegreeProgram GetDegreeProgram();
    

    //setters
    void SetStudentID(string studentID);
    void SetFirstName(string firstName);
    void SetLastName(string lastName);
    void SetEmailAddress(string emailAddress);
    void SetAge(int age);
    void SetDaysCompleted(int daysToComplete[3]);
    void SetDegreeProgram(DegreeProgram degreeProgram);

    //constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysCompleted[3], DegreeProgram degreeProgram);
    Student();

    // Print student data
    void Print();

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysCompleted[3];
    DegreeProgram degreeProgram;
};
