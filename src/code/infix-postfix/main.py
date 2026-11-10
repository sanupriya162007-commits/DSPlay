# Infix to Postfix using a stack
# Example: A+B*C  ->  ABC*+

def precedence(op):                  # higher number = done first
    if op in "*/":
        return 2
    if op in "+-":
        return 1
    return 0

infix = "A+B*C"
postfix = ""
stack = []

for c in infix:
    if c.isalnum():                  # operand: send to output
        postfix += c
    elif c == "(":
        stack.append(c)
    elif c == ")":                   # pop until '('
        while stack and stack[-1] != "(":
            postfix += stack.pop()
        stack.pop()                  # throw away '('
    else:                            # operator
        while stack and precedence(stack[-1]) >= precedence(c):
            postfix += stack.pop()
        stack.append(c)

while stack:                         # empty the stack
    postfix += stack.pop()

print("Infix:  ", infix)
print("Postfix:", postfix)
