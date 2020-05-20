//
//  roster.hpp
//  student roster
//
//  Created by Jon on 5/11/20.
//  Copyright © 2020 Jon Lambson. All rights reserved.
//

#ifndef roster_h
#define roster_h
#include "student.h"
#include <stdio.h>
using namespace std;

class Roster {
    public:
        int index;
        int size;
        //int classRosterArraySize = 5;
        Student *classRosterArray;
    
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
        void remove(string studentID);
        void printAll();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
    
        void parse(string row);
    
        // Constructor
        Roster();
        Roster(int size);
        //Roster(int numberOfStudents);
        // Deconstructor
        ~Roster();
};

#endif /* roster_h */
