// Evaluate a postfix expression using a stack
// Example: 5 2 3 * +  ->  5 + (2*3) = 11
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int stack[50];
int top = -1;

int main() {
    char expr[] = "523*+";      // single-digit numbers, no spaces

    for (int i = 0; i < strlen(expr); i++) {
        char c = expr[i];

        if (isdigit(c)) {
            stack[++top] = c - '0';        // push the number
        } else {
            int right = stack[top--];      // pop right operand first
            int left  = stack[top--];      // then left operand
            int result = 0;

            if (c == '+') result = left + right;
            if (c == '-') result = left - right;
            if (c == '*') result = left * right;
            if (c == '/') result = left / right;

            stack[++top] = result;         // push the answer back
        }
    }
    printf("Result: %d\n", stack[top]);
    return 0;
}
