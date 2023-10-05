#include <iostream>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <vector>       
#include <sstream>       
#include <string>        

int main() {
    // print course title, programming language, student ID, and name
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "Course: Scripting and Programming - Applications - C867" << std::endl;
    std::cout << "Programming Language: C++" << std::endl;
    std::cout << "WGU Student ID: 009588480" << std::endl;
    std::cout << "Name: Brandon Council" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << std::endl;
    std::cout << "Displaying all students:" << std::endl;

    // student data
    const std::string studentData[numStudents] = {
        "A1,John,Smith,John1989@g mail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Brandon,Council,bcoun15@wgu.edu,36,30,45,25,SOFTWARE"
    };

    // create a Roster instance
    Roster classRoster;


    for (int i = 0; i < numStudents; i++) {

        std::stringstream ss(studentData[i]);

        std::string item;
        std::vector<std::string> result;

        while (std::getline(ss, item, ',')) {
            result.push_back(item);
        }

        int age = stoi(result[4]);
        int daysInCourse1 = stoi(result[5]);
        int daysInCourse2 = stoi(result[6]);
        int daysInCourse3 = stoi(result[7]);

        DegreeProgram dp;
        if (result[8] == "SECURITY") dp = SECURITY;
        else if (result[8] == "NETWORK") dp = NETWORK;
        else dp = SOFTWARE;

        classRoster.add(result[0], result[1], result[2], result[3], age, daysInCourse1, daysInCourse2, daysInCourse3, dp);
    }

    classRoster.printAll();
    std::cout << std::endl;
    std::cout << "Showing all invalid emails:" << std::endl;
    std::cout << std::endl;
    classRoster.printInvalidEmails();

    // print average days in course
    std::cout << std::endl;
    std::cout << "The average number of day in the course by student id:" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < numStudents; i++) {
        if (classRoster.GetRosterArray()[i] != nullptr) {
            classRoster.printAverageDaysInCourse(classRoster.GetRosterArray()[i]->GetStudentID());
        }
    }
    std::cout << std::endl;
    std::cout << "Student(s) currently in degree program: SOFTWARE" << std::endl;
    std::cout << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    std::cout << std::endl;
    classRoster.printAll();
    std::cout << std::endl;
    classRoster.remove("A3");
    std::cout << std::endl;

    std::cout << "Finished." << std::endl;

    return 0;
}
