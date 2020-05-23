//
//  roster.hpp
//  student roster
//
//  Created by Jon on 5/11/20.
//  Copyright © 2020 Jon Lambson. All rights reserved.
//

#ifndef roster_h
#define roster_h
#include <stdio.h>
#include "student.h"

class Roster {
        size_t size;
        //int classRosterArraySize = 5;
        Student *classRosterArray;
    public:
        Roster();
        Roster(const std::size_t size);

        ~Roster();
        void add(const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& emailAddress,  std::size_t age, const std::size_t daysInCourse1, const std::size_t daysInCourse2, const std::size_t daysInCourse3, const DegreeProgram& degreeprogram);
        void remove(const std::string& studentID);
        void printAll();
        void printAverageDaysInCourse(const std::string& studentID);
        void printInvalidEmails();
        void printByDegreeProgram(const DegreeProgram& degreeProgram);
    
        void parse(const std::string& row);

};

#endif /* roster_h */
