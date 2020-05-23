//
//  student.cpp
//  student roster
//
//  Created by Jon on 5/5/20.
//  Copyright © 2020 Jon Lambson. All rights reserved.
//

#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;

Student::Student() {
    this->studentId = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    numberOfDaysToComplete = new size_t[daysInCourseArraySize]{};
    this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(const string& id, const string& first, const string& last, const string& email, u_int8_t years, const size_t* numOfDays, const DegreeProgram& degreeProgram) {
    studentId = id;
    firstName = first;
    lastName = last;
    emailAddress = email;
    age = years;
    numberOfDaysToComplete = new size_t[daysInCourseArraySize]{};
    memcpy(numberOfDaysToComplete, numOfDays, daysInCourseArraySize);
    
    this->degreeProgram = degreeProgram;
}
// Get
string Student::getId() {
    return studentId;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmailAddress() {
    return emailAddress;
}

int Student::getAge() {
    return age;
}

const size_t* Student::getNumberOfDaysToComplete() {
    return numberOfDaysToComplete;
}

DegreeProgram Student::getDegreeProgram()
{
    return degreeProgram;
}

// Set
void Student::setId(string id) {
    studentId = id;
}

void Student::setFirstName(string first) {
    firstName = first;
}

void Student::setLastName(string last) {
    lastName = last;
}

void Student::setEmailAddress(string email) {
    emailAddress = email;
}

void Student::setAge(int age) {
     this->age = age;
}

void Student::setNumberOfDaysToComplete(int days[]) {
    for (int i = 0; i < daysInCourseArraySize; ++i) {
        numberOfDaysToComplete[i] = days[i];
    }
}

void Student::setDegreeProgram(const DegreeProgram& degreeProgram)
{
    this->degreeProgram = degreeProgram;
}

void Student::print() {
    cout << "Student ID: " << studentId << endl;;
    cout << "First Name: " << firstName << endl;;
    cout << "Last Name: " << lastName  << endl;
    cout << "Email Address: " << emailAddress  << endl;
    cout << "Age: "  << age << endl;
    cout << "DaysInCourse: {";
    
    for (auto curr = numberOfDaysToComplete; curr < numberOfDaysToComplete + daysInCourseArraySize; ++curr) {
        cout << *curr << endl;
    }
    
    cout << "}" << '\t' << endl;
    cout << "Degree Prog88sram: " << degreeProgram << endl;
    cout << "Degree Program: " << degreeProgramStrings[degreeProgram] << endl;
    cout << "------------------------------------------" << endl;
}

Student::~Student() {}
