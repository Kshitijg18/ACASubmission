#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double calculate(double num1, double num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                cout << "Error: Division by zero is not allowed." << endl;
                return 0;
            }
            return num1 / num2;
        case '%':
            if (num2 == 0) {
                cout << "Error: Modulus with zero is not allowed." << endl;
                return 0;
            }
            return fmod(num1, num2);
        default:
            cout << "Invalid operator." << endl;
            return 0;
    }
}

double trigFunction(double num, string op) {
    if (op == "sin") {
        return sin(num);
    } else if (op == "cos") {
        return cos(num);
    } else if (op == "tan") {
        return tan(num);
    } else {
        cout << "Invalid trigonometric function." << endl;
        return 0;
    }
}

double exponentialFunction(double num, string op) {
    if (op == "exp") {
        return exp(num);
    } else if (op == "log") {
        double base;
        cout << "Enter the base for the logarithm: ";
        cin >> base;
        return log(num) / log(base);
    } else {
        cout << "Invalid exponential function." << endl;
        return 0;
    }
}

int main() {
    double num1, num2;
    char op;
    string trigOp, expOp;

    while (true) {
        cout << "Welcome to the Calculator!" << endl;
        cout << "Enter the first number: ";
        cin >> num1;

        cout << "Enter the operator (+, -, *, /, %, sin, cos, tan, exp, log): ";
        cin >> op;

        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%') {
            cout << "Enter the second number: ";
            cin >> num2;
            double result = calculate(num1, num2, op);
            cout << "Result: " << num1 << " " << op << " " << num2 << " = " << result << endl;
        } else if (op == 's' || op == 'c' || op == 't') {
            cout << "Enter the trigonometric function (sin, cos, tan): ";
            cin >> trigOp;
            double result = trigFunction(num1, trigOp);
            cout << "Result: " << trigOp << "(" << num1 << ") = " << result << endl;
        } else if (op == 'e' || op == 'l') {
            cout << "Enter the exponential function (exp, log): ";
            cin >> expOp;
            double result = exponentialFunction(num1, expOp);
            if (expOp == "exp") {
                cout << "Result: exp(" << num1 << ") = " << result << endl;
            } else {
                cout << "Result: log(" << num1 << ") = " << result << endl;
            }
        } else {
            cout << "Invalid operator." << endl;
        }

        char choice;
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    cout << "Thank you for using the Calculator!" << endl;
    return 0;
}