#ifndef READWRITE_H
#define READWRITE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <stdio.h>

using namespace std;


struct Student {
    string ID;
    string Course;
    string Grade;
    string InstructorID;
};

struct Instructor {
    string ID;
    string Course;
    string Term;
};

struct Term {
    string ID;
    string DisplayName;
};

struct Course {
    string ID;
    string CourseNumber;
    string SectionCode;
    string Term;
};

class Enrollment {
    public:
        Enrollment();
        void update(string, string, string, string, string, string);
        void read(string);
        void write(string);
        void pass_rate_per_instructor();
        void w_rate_per_instructor();
        void fall_vs_spring();
        void display();
    private:
        vector<Student> students;
        vector<Instructor> instructors;
        vector<Term> terms;
        vector<Course> courses;
        map<string, int> pass_rate_per_instructor_map;
        map<string, int> w_rate_per_instructor_map;
        map<string, int> fall_vs_spring_map;
        map<string, int>::iterator it;


};

#endif