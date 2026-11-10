# Evaluate a postfix expression using a stack
# Example: 5 2 3 * +  ->  5 + (2*3) = 11

expression = "5 2 3 * +"      # numbers and operators separated by spaces
stack = []

for token in expression.split():
    if token.isdigit():
        stack.append(int(token))       # push the number
    else:
        right = stack.pop()            # pop right operand first
        left = stack.pop()             # then left operand

        if token == "+":
            result = left + right
        elif token == "-":
            result = left - right
        elif token == "*":
            result = left * right
        else:
            result = left // right

        stack.append(result)           # push the answer back

print("Result:", stack[-1])
