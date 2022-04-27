
#include<iostream>
#include<string>
#include "readwrite.h"

int main() {
    Enrollment enrollment;
    enrollment.read("data/3115.csv");
    enrollment.read("data/3130.csv");
    enrollment.read("data/1115.csv");
    enrollment.write("output/3115_out.csv");
    enrollment.write("output/3130_out.csv");
    enrollment.write("1115_out.csv");
    enrollment.pass_rate_per_instructor();
    enrollment.w_rate_per_instructor();
    enrollment.fall_vs_spring();
    enrollment.display();
    return 0;
}