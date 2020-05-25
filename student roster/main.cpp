//
//  main.cpp
//  student roster
//
//  Created by Jon on 5/14/20.
//  Copyright © 2020 Jon Lambson. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <array>
#include "degree.h"
#include "roster.h"
#include "student.h"
using namespace std;

int main() {
    cout << endl << endl;
    cout << "Course Title:\t\t\t\tScripting and Programming - Applications - C867";
    cout << endl;
    cout << "Programming language used:\tC++";
    cout << endl;
    cout << "WGU Student ID:\t\t\t\t000857091";
    cout << endl;
    cout << "Name:\t\t\t\t\t\tJon Lambson";
    cout << endl << endl;
    
    Roster* classRoster = new Roster();
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jonathan,Lambson,jlambs1@wgu.edu,33,50,40,22,SOFTWARE"
    };
    
    for (int i = 0; i < sizeof(studentData)/sizeof(studentData[0]); ++i) {
        classRoster->parse(studentData[i]);
    }
//    cout << "----------------------------------------------------------" << endl;
//    cout << "PRINT ALL: " << endl;
//    cout << "----------------------------------------------------------" << endl;
    classRoster->printAll();
    
//    cout << "----------------------------------------------------------" << endl;
//    cout << "INVALID EMAILS: " << endl;
//    cout << "----------------------------------------------------------" << endl;
    classRoster->printInvalidEmails();
    cout << endl;
     
    int cheapTrick = 1;
//    cout << "----------------------------------------------------------" << endl;
//    cout << "AVERAGE DAYS IN COURSE: " << endl;
//    cout << "----------------------------------------------------------" << endl;
    for (int i = 0; i < sizeof(studentData)/sizeof(studentData[0]); ++i) {
        classRoster->printAverageDaysInCourse("A" + std::to_string(cheapTrick));
        cheapTrick++;
    }
    cout << endl;
    
//    cout << "----------------------------------------------------------" << endl;
//    cout << "STUDENTS BY DEGREE PROGRAM: " << endl;
//    cout << "----------------------------------------------------------" << endl;
    classRoster->printByDegreeProgram(SOFTWARE);
    
    classRoster->remove("A3");
    
//    cout << "----------------------------------------------------------" << endl;
//    cout << "PRINT ALL: " << endl;
//    cout << "----------------------------------------------------------" << endl;
    classRoster->printAll();

    
    classRoster->remove("A3");
    //expected: the above line should print a message saying such a student with this ID was not found.
    
    cout << endl << endl;
}
