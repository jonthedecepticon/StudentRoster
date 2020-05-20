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
    for (int i = 0; i < daysInCourseArraySize; ++i) this->numberOfDaysToComplete[i] = 0;
}

Student::Student(string id, string first, string last, string email, int years, int numOfDays[], DegreeProgram degree) {
    studentId = id;
    firstName = first;
    lastName = last;
    emailAddress = email;
    age = years;
    for (int i = 0; i < daysInCourseArraySize; ++i) this->numberOfDaysToComplete[i] = numberOfDaysToComplete[i];
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

int* Student::getNumberOfDaysToComplete() {
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

void Student::setDegreeProgram(DegreeProgram degreeProgram)
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
    for (int i = 0; i < 3; i++ ) {
        if (i < 2 ) {
            cout << numberOfDaysToComplete[i] << ", ";
        } else {
            cout << numberOfDaysToComplete[i];
        }
    }
    cout << "}"  << endl;
    cout << "Degree Program: " << degreeProgram << endl;
}

Student::~Student() {}
