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
    cout << "Course Title:\tScripting and Programming - Applications - C867";
    cout << endl;
    cout << "Programming language used:\tC++";
    cout << endl;
    cout << "WGU Student ID:\t\t\t\t000857091";
    cout << endl;
    cout << "Name:\t\t\t\t\t\tJon Lambson";
    cout << endl << endl;
    
    Roster* classRoster = new Roster();
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jonathan,Lambson,jlambs1@wgu.edu,33,50,40,22,SOFTWARE"
    };
    

    for (int i = 0; i < sizeof(studentData)/sizeof(studentData[0]); ++i) {
        classRoster->parse(studentData[i]);
        cout << endl;
    };
    
//    classRoster.add(currentStudentID, currentFirstName, currentLastName, currentEmailAddress, currentAge, currentDaysInCourse[0], currentDaysInCourse[1], currentDaysInCourse[2], i, currentDegreeProgram);
}
