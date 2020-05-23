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

bool *classRosterArrayIsDeleted;

Roster::Roster() {
    this->size = 0;
    this->classRosterArray = new Student[5]{};
    classRosterArrayIsDeleted = new bool[5]{};
}

Roster::Roster(size_t size) {
    this->size = size;
    this->classRosterArray = new Student[size]{};
}

Roster::~Roster() {
    delete [] classRosterArray;
}

void Roster::parse(const string& row){
    Student *student;
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
    size_t age = 0;
    size_t daysInCourse1 = 0;
    size_t daysInCourse2 = 0;
    size_t daysInCourse3 = 0;
    DegreeProgram degree;
    
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
                age = stoul(v[i]);
              break;
          case 5 :
                daysInCourse1 = stoul(v[i]);
               break;
          case 6 :
                daysInCourse2 = stoul(v[i]);
             break;
          case 7 :
                daysInCourse3 = stoul(v[i]);
             break;
          case 8 :
                degree = DegreeProgram::NETWORK;
             break;
           default :
                cout << "Error: too many items" << endl;
        }
    }
    
    // Seperate logic - return a Student obj; that would be used in the ::add
    // Student student = Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
    
    
    
    add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
}

void Roster::add(const string& studentID, const  string& firstName, const  string& lastName, const  string& emailAddress, size_t age, const size_t daysInCourse1, const size_t daysInCourse2, const size_t daysInCourse3, const DegreeProgram& degreeProgram) {
    
    // size_t courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    Student student = Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
    
    
    memcpy(classRosterArray + size++, &student, sizeof(Student));
}

void Roster::remove(const string& studentID) {
    auto curr = classRosterArray;
    auto lastIdx = classRosterArray + size;
    for (; curr <= lastIdx; ++curr) {
        if (curr->getId() != studentID || classRosterArrayIsDeleted[curr - classRosterArray])
            continue;
        
        classRosterArrayIsDeleted[curr - classRosterArray] = true;
        break;
    }
    if (curr == lastIdx)
        cout << "Error: Student Id not found";
}

void Roster::printAll() {
    for (auto curr = classRosterArray; curr < classRosterArray + size; ++curr) {
        curr->print();
    }
}

void Roster::printAverageDaysInCourse(const string& studentID) {
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

void Roster::printByDegreeProgram(const DegreeProgram& degreeProgram){
    cout << "Printing students with degree type: " << degreeProgramStrings[degreeProgram] << endl;
    
    for (auto curr = classRosterArray; curr < classRosterArray + size; ++curr) {
        if(curr->getDegreeProgram() != degreeProgram)
            continue;
        
        curr->print();
    }
}
