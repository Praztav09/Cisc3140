#include "readwrite.h"
#include<string>
Enrollment::Enrollment() {
    pass_rate_per_instructor_map.clear();
    w_rate_per_instructor_map.clear();
    fall_vs_spring_map.clear();
}

void Enrollment::update(string ID, string courseID, string InstructorID, string termID, string SectionCode, string Grade) {
    Student student;
    Instructor instructor;
    Term term;
    Course course;

    student.ID = ID;
    student.Course = courseID;
    student.Grade = Grade;
    student.InstructorID = InstructorID;
    students.push_back(student);

    instructor.ID = InstructorID;
    instructor.Course = courseID;
    instructor.Term = termID;
    instructors.push_back(instructor);

    term.ID = termID;
    term.DisplayName = "";
    terms.push_back(term);

    course.ID = courseID;
    course.CourseNumber = courseID;
    course.SectionCode = SectionCode;
    course.Term = termID;
    courses.push_back(course);
}

void Enrollment::read(string filename) {
    ifstream file(filename);
    string line;
    string ID;
    string Course;
    string InstructorID;
    string Term;
    string SectionCode;
    string Grade;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, ID, ' ');
            getline(ss, Course, ' ');
            getline(ss, InstructorID, ' ');
            getline(ss, Term, ' ');
            getline(ss, SectionCode, ' ');
            getline(ss, Grade, ' ');
            update(ID, Course, InstructorID, Term, SectionCode, Grade);
        }
    }
    file.close();
}

void Enrollment::write(string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < students.size(); i++) {
            file << students[i].ID << "," << students[i].Course << "," << students[i].InstructorID << "," << students[i].Grade << endl;
        }
    }
    file.close();
}

void Enrollment::pass_rate_per_instructor() {
    int pass_rate = 0;
    int total = 0;
    for (int i = 0; i < instructors.size(); i++) {
        for (int j = 0; j < students.size(); j++) {
            if (instructors[i].ID == students[j].InstructorID) {
                if (students[j].Grade == "A" || students[j].Grade == "A-" || students[j].Grade == "B+" || students[j].Grade == "B" || students[j].Grade == "B-" || students[j].Grade == "C+" || students[j].Grade == "C" || students[j].Grade == "C-" || students[j].Grade == "D+" || students[j].Grade == "D" || students[j].Grade == "D-") {
                    pass_rate++;
                }
                total++;
            }
        }
        pass_rate_per_instructor_map[instructors[i].ID] = pass_rate;
        pass_rate = 0;
        total = 0;
    }
}

void Enrollment::w_rate_per_instructor() {
    int w_rate = 0;
    int total = 0;
    for (int i = 0; i < instructors.size(); i++) {
        for (int j = 0; j < students.size(); j++) {
            if (instructors[i].ID == students[j].InstructorID) {
                if (students[j].Grade == "W") {
                    w_rate++;
                }
                total++;
            }
        }
        w_rate_per_instructor_map[instructors[i].ID] = w_rate;
        w_rate = 0;
        total = 0;
    }
}

void Enrollment::fall_vs_spring() {
    int fall = 0;
    int spring = 0;
    for (int i = 0; i < terms.size(); i++) {
        if (terms[i].ID == "T04" || terms[i].ID == "T08" || terms[i].ID == "T12" || terms[i].ID == "T16" || terms[i].ID == "T20" || terms[i].ID == "T23") {
            fall++;
        }
        else if (terms[i].ID == "T02" || terms[i].ID == "T06" || terms[i].ID == "T10" || terms[i].ID == "T14" || terms[i].ID == "T18" || terms[i].ID == "T21") {
            spring++;
        }
    }
    fall_vs_spring_map["Fall"] = fall;
    fall_vs_spring_map["Spring"] = spring;
}

void Enrollment::display() {
    cout << "Pass rate per instructor:" << endl;
    for (it = pass_rate_per_instructor_map.begin(); it != pass_rate_per_instructor_map.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
    cout << endl;
    cout << "W rate per instructor:" << endl;
    for (it = w_rate_per_instructor_map.begin(); it != w_rate_per_instructor_map.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
    cout << endl;
    cout << "Fall vs Spring pass rate for each course:" << endl;
    for (it = fall_vs_spring_map.begin(); it != fall_vs_spring_map.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
}