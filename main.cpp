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

enum class operation{
    add,
    sub,
    divide,
    mul,
    squareroot,
    exponent
};

struct calculator{
    double num1;
    double num2;
    operation op;
};

int calculate(double num1,
    double num2,
    operation op){
    switch(op){
        case operation::add:
            cout<<"The sum is: "<<num1+num2<<endl;
            break;
        case operation::sub:
            cout<<"The difference is: "<<num1-num2<<endl;
            break;
        case operation::divide:
            if(num2==0){
                cout<<"Divide by zero error"<<endl;
            }
            else{
                cout<<"The quotient is: "<<num1/num2<<endl;
            }
            break;
        case operation::mul:
            cout<<"The product is: "<<num1*num2<<endl;
            break;
        case operation::squareroot:
            if(num1<0){
                cout<<"Invalid input"<<endl;
            }
            else{
                cout<<"The square root is: "<<sqrt(num1)<<endl;
            }
            break;
        case operation::exponent:
            cout<<"The exponent is: "<<pow(num1,num2)<<endl;
            break;
    }
		return 0;
}

int main(){
    calculator c; 
	string opt;
	cout << "Enter first number: ";
    cin >> c.num1;
	cout << "Enter operator: ";
	cin >> opt;
    cout << "Enter second number: ";
    cin >> c.num2;
	operation op{};

    if (opt == "add") {
        op = operation::add;
    } else if (opt == "sub") {
        op = operation::sub;
    } else if (opt == "mul") {
        op = operation::mul;
    } else if (opt == "div") {
        op = operation::divide;
    }else if (opt == "squareroot") {
        op = operation::squareroot;
    }else if (opt == "exponent") {
        op = operation::exponent;
    }


        
    //cin>>c.num1>>c.op>>c.num2;
    calculate(c.num1, c.num2, c.op);
    return 0;
}
