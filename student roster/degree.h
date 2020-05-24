//
//  degree.h
//  student roster
//
//  Created by Jon on 5/5/20.
//  Copyright © 2020 Jon Lambson. All rights reserved.
//

#ifndef degree_h
#define degree_h

enum DegreeProgram {
    SECURITY, NETWORK, SOFTWARE
};

static const std::string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };

static DegreeProgram getDegreeProgram(std::string degree) {
    for (int i = 0; i < sizeof(degreeProgramStrings); ++i)
        if (degree == degreeProgramStrings[i])
            return static_cast<DegreeProgram>(i);
    
    return DegreeProgram::SECURITY;
}

#endif /* degree_h */
