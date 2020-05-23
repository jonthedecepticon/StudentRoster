//
//  student.h
//  student roster
//
//  Created by Jon on 5/5/20.
//  Copyright © 2020 Jon Lambson. All rights reserved.
//

#ifndef student_h
#define student_h

#include <stdio.h>
#include "degree.h"

class Student {
    const static int daysInCourseArraySize = 3;
    std::string studentId;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    std::size_t* numberOfDaysToComplete;
    DegreeProgram degreeProgram;
    
    public:
        // Contstructor
        Student();
        Student(const std::string& id, const std::string& first, const std::string& last, const std::string& email, const u_int8_t years, const std::size_t* numOfDays, const DegreeProgram& degree);
    
        // Decontstructor
        ~Student();
    
        //size_t
    
        // Get
        std::string getId();
        std::string getFirstName();
        std::string getLastName();
        std::string getEmailAddress();
        int getAge();
        const std::size_t* getNumberOfDaysToComplete();
        DegreeProgram getDegreeProgram();
        // Set
        void setId(std::string studentId);
        void setFirstName(std::string firstName);
        void setLastName(std::string lastName);
        void setEmailAddress(std::string email);
        void setAge(int age);
        void setNumberOfDaysToComplete(int days[3]);
        void setDegreeProgram(const DegreeProgram& degree);
        void print();
    

};

#endif /* student_h */
