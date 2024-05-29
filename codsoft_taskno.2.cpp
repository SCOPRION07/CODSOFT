// SIMPLE CALCULATOR //
#include <iostream>
using namespace std;

int main() {
    char op;
    float num1, num2, result;
    while (true) { 
        cout << "Choose an arithmetic operator (+, -, *, /) to perform: ";
        cin >> op;
        
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;
        
        if(op == '+') {
            result = num1 + num2;
            cout << "Result: " << result << endl;
           
        } else if(op == '-') {
            result = num1 - num2;
            cout << "Result: " << result << endl;
          
        } else if(op == '*') {
            result = num1 * num2;
            cout << "Result: " << result << endl;
            
        } else if(op == '/') {
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            } else {
                cout << "Division by zero is not possible!" << endl;
            }
            
        } else {
            cout << "Error: Invalid operator!" << endl;
        }
    }
    return 0;
}
