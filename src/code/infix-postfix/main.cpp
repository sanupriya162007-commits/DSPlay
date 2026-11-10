// Infix to Postfix using a stack
// Example: A+B*C  ->  ABC*+
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {          // higher number = done first
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    string infix = "A+B*C";
    string postfix = "";
    stack<char> s;

    for (char c : infix) {
        if (isalnum(c)) {                       // operand: send to output
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {                  // pop until '('
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();                            // throw away '('
        } else {                                // operator
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {                        // empty the stack
        postfix += s.top();
        s.pop();
    }

    cout << "Infix:   " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    return 0;
}
