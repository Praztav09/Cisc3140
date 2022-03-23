/*
Create a calculator program that:
1. has enum class for add, sub, divide, mul, squareroot, exponent.
2. has struct methods.
3. handles divide by zero error.
4. handles invalid input.
*/

#include<iostream>
#include<cmath>
using namespace std;


enum class OPERATOR {
    ADD,
    SUB,
    DIV,
    MUL,
    SQRT,
    EXP
};

struct Calculator {
 
    double first_number;
    double second_number;
    OPERATOR operator_type;
 
       void get_input() {
        cout << "Enter first number: ";
        cin >> first_number;
        cout << "Enter second number: ";
        cin >> second_number;
        cout << "Enter operator: ";
        string op;
        cin>> op;
        if (op == "+") {
            operator_type = OPERATOR::ADD;
        } else if (op == "-") {
            operator_type = OPERATOR::SUB;
        } else if (op == "/") {
            operator_type = OPERATOR::DIV;
        } else if (op == "*") {
            operator_type = OPERATOR::MUL;
        } else if (op == "sqrt") {
            operator_type = OPERATOR::SQRT;
        } else if (op == "^") {
            operator_type = OPERATOR::EXP;
        } else {
            cout << "Invalid operator" << endl;
            exit(1);
        }
    }
 
    double calculate() {
        switch (operator_type) {
            case OPERATOR::ADD:
                return first_number + second_number;
            case OPERATOR::SUB:
                return first_number - second_number;
            case OPERATOR::DIV:
                if (second_number == 0) {
                    cout << "Divide by zero error!" << endl;
                    get_input();
                }
                return first_number / second_number;
            case OPERATOR::MUL:
                return first_number * second_number;
            case OPERATOR::SQRT:
                if (first_number < 0) {
                    cout << "Invalid number!" << endl;
                    get_input();
                }
                return sqrt(first_number);
            case OPERATOR::EXP:
                return pow(first_number, second_number);
            
            }
            return 0;
        }
    
    };
 
int main() {
    Calculator calc;
    calc.get_input();
    cout << calc.calculate() << endl;
    return 0;
}
