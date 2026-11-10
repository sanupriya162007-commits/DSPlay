// Infix to Postfix using a stack
// Example: A+B*C  ->  ABC*+
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

int precedence(char op) {          // higher number = done first
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char infix[] = "A+B*C";
    char postfix[50];
    int j = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if (isalnum(c)) {                       // operand: send to output
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {                  // pop until '('
            while (top != -1 && stack[top] != '(') postfix[j++] = pop();
            pop();                              // throw away '('
        } else {                                // operator
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }
    while (top != -1) postfix[j++] = pop();     // empty the stack
    postfix[j] = '\0';

    printf("Infix:   %s\n", infix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
