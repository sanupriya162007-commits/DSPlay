// Evaluate a postfix expression using a stack
// Example: 5 2 3 * +  ->  5 + (2*3) = 11
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string expr = "523*+";      // single-digit numbers, no spaces
    stack<int> s;

    for (char c : expr) {
        if (isdigit(c)) {
            s.push(c - '0');               // push the number
        } else {
            int right = s.top(); s.pop();  // pop right operand first
            int left  = s.top(); s.pop();  // then left operand
            int result = 0;

            if (c == '+') result = left + right;
            if (c == '-') result = left - right;
            if (c == '*') result = left * right;
            if (c == '/') result = left / right;

            s.push(result);                // push the answer back
        }
    }
    cout << "Result: " << s.top() << endl;
    return 0;
}
