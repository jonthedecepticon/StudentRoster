//
//  roster.cpp
//  student roster
//
//  Created by Jon on 5/11/20.
//  Copyright © 2020 Jon Lambson. All rights reserved.
//
  
#include <iostream>
#include <sstream>
#include <vector>
#include "roster.h"
#include "student.h"

using namespace std;

Roster::Roster() {
    this->size = 0;
    this->index = -1;
    this->classRosterArray = new Student[5];
}

Roster::Roster(int size) {
    this->size = size;
    this->index = -1;
    this->classRosterArray = new Student[size];
}

Roster::~Roster() {
//    for (int i = 0; i <= classRosterArray.size(); i++)
//    {
//        delete this->classRosterArray[i];
//    }
//    delete classRosterArray;
}

void Roster::parse(string row){
    Student student;
    vector<string> v{};
    
    stringstream ss(row);

    while (ss.good()) {
      string substr;
      getline(ss, substr, ',');
      v.push_back(substr);
    }
    
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age = 0;
    int daysInCourse1 = 0;
    int daysInCourse2 = 0;
    int daysInCourse3 = 0;
    DegreeProgram degree = DegreeProgram::SOFTWARE;
    
    for (size_t i = 0; i < v.size(); i++) {
        switch(i) {
           case 0 :
                studentID = v[i];
              break;
           case 1 :
                firstName = v[i];
                break;
           case 2 :
                lastName = v[i];
              break;
           case 3 :
                email = v[i];
              break;
           case 4 :
                age = stoi(v[i]);
              break;
          case 5 :
                daysInCourse1 = stoi(v[i]);
               break;
          case 6 :
                daysInCourse2 = stoi(v[i]);
             break;
          case 7 :
                daysInCourse3 = stoi(v[i]);
             break;
          case 8 :
                degree = DegreeProgram::SOFTWARE;
             break;
           default :
                cout << "Error: too many items" << endl;
        }
    }
   Student student = Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
//    add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    Student student = Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);

    *(classRosterArray + index) = student;
}

void Roster::remove(string studentID) {
}

void Roster::printAll() {
    for (int i = 0; i <= 5; ++i)
    {
//        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
//    int average = 0;
//
//    for (int i = 0; i < 5; ++i) {
//        string tempId = classRosterArray[i]->getId();
//        cout << "tempId" << tempId << endl;
//        cout << "studentID" << studentID << endl;
//    }
}

void Roster::printInvalidEmails(){
    
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    
}
