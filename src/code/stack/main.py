# Stack using a Python list (LIFO: Last In, First Out)

stack = []   # an empty list is our stack

def push(value):
    stack.append(value)          # add to the top

def pop():
    if len(stack) == 0:
        print("Stack is empty")
        return
    print("Popped:", stack.pop())  # remove from the top

def peek():
    if len(stack) == 0:
        print("Stack is empty")
    else:
        print("Top value:", stack[-1])  # last item = top

push(10)
push(20)
push(30)
peek()   # 30
pop()    # 30
pop()    # 20
peek()   # 10
