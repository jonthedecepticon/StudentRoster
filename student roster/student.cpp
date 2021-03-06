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
    memcpy(numberOfDaysToComplete, numOfDays, daysInCourseArraySize * sizeof(size_t));
    this->degreeProgram = degreeProgram;
}

Student::~Student() {
    //delete [] numberOfDaysToComplete;
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
void Student::setId(const string& id) {
    studentId = id;
}

void Student::setFirstName(const string& first) {
    firstName = first;
}

void Student::setLastName(const string& last) {
    lastName = last;
}

void Student::setEmailAddress(const string& email) {
    emailAddress = email;
}

void Student::setAge(const size_t age) {
     this->age = age;
}

void Student::setNumberOfDaysToComplete(const size_t days[]) {
    for (int i = 0; i < daysInCourseArraySize; ++i) {
        numberOfDaysToComplete[i] = days[i];
    }
}

void Student::setDegreeProgram(const DegreeProgram& degreeProgram) {
    this->degreeProgram = degreeProgram;
}

void Student::print() {
    cout << "Student ID:\t" << studentId;
    cout << " First Name:\t" << firstName;
    cout << " Last Name:\t" << lastName;
    cout << " Email Address:\t" << emailAddress;
    cout << " Age:\t"  << age;
    cout << " DaysInCourse: {";

    for (auto curr = numberOfDaysToComplete; curr < numberOfDaysToComplete + daysInCourseArraySize; curr++) {
        cout << *curr << ",";
    }
    
    cout << "}" << "\t";
    cout << " Degree Program: " << degreeProgramStrings[degreeProgram] << endl;
    cout << endl;
}
