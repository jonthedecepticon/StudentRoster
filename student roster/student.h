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
using namespace std;

class Student {
    public:
        const static int daysInCourseArraySize = 3;
        // Get
        string getId();
        string getFirstName();
        string getLastName();
        string getEmailAddress();
        int getAge();
        int* getNumberOfDaysToComplete();
        DegreeProgram getDegreeProgram();
        // Set
        void setId(string studentId);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmailAddress(string email);
        void setAge(int age);
        void setNumberOfDaysToComplete(int days[]);
        void setDegreeProgram(DegreeProgram degree);
        void print();
    
        // Contstructor
        Student();
        Student(string studentID, string first, string last, string email, int years, int numOfDays[], DegreeProgram degree);
    
        // Decontstructor
        ~Student();
    
    private:
         string studentId;
         string firstName;
         string lastName;
         string emailAddress;
         int age;
         int numberOfDaysToComplete[daysInCourseArraySize];
         DegreeProgram degreeProgram;
};

#endif /* student_h */
