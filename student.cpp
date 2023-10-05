#include <iostream>
#include "student.h"
using std::cout;
using std::endl;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysCompleted[0] = 0;
	this->daysCompleted[1] = 0;
	this->daysCompleted[2] = 0;
	this->degreeProgram = DegreeProgram::UNKNOWN;

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysCompleted[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysCompleted[0] = daysCompleted[0];
	this->daysCompleted[1] = daysCompleted[1];
	this->daysCompleted[2] = daysCompleted[2];
	this->degreeProgram = degreeProgram;
	}
	
	Student::~Student() {
		
	}
//getters
	string Student::getStudentID(){
		return this->studentID;
	}
	string Student::getFirstName(){
		return this->firstName;
	}
	string Student::getLastName(){
		return this->lastName;
	}
	string Student::getEmailAddress(){
		return this->emailAddress;
	}
	int Student::getAge(){
		return this->age;
	}

	int* Student::getDaysCompleted(){
		return this->daysCompleted;
	}
	DegreeProgram Student::getDegreeProgram(){
		return this->degreeProgram;
	}
//setters

void Student::setstudentID(string studentID) {
	return this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	return this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	return this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	return	this->emailAddress = emailAddress;
}
void Student::setAge(int studentAge) {
	return this->age = studentAge;
}

void Student::setDaysCompleted(int daysCompleted1, int daysCompleted2, int daysCompleted3) {
	for (int i = 0; i < 3; i++)
	this->daysCompleted[0] = daysCompleted1;
	this->daysCompleted[1] = daysCompleted2;
	this->daysCompleted[2] = daysCompleted3;
}
void Student::setDegreeProgram(DegreeProgram degreeprogram) {
	return this->degreeProgram = degreeprogram;
}
//print

void Student::printstudentID() {
	return cout << this->studentID << endl;
}
void Student::printFirstName() {
	return cout << this->firstName << endl;
}
void Student::printLastName() {
	return cout << this->lastName << endl;
}
void Student::printEmailAddress() {
	return cout << this->emailAddress << endl;
}
void Student::printAge() {
	return cout << this->age << endl;
}
void Student::PrintDaysCompleted() {
	return cout << this->daysCompleted1 << " " << daysCompleted2 << " " << daysCompleted3 << endl; 
}
void Student::PrintDegreeProgram() {
	return cout << this->DegreeProgram[degreeProgram] << endl;
}