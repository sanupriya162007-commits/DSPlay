# Queue using a Python list (FIFO: First In, First Out)

queue = []   # an empty list is our queue

def enqueue(value):
    queue.append(value)            # add at the back

def dequeue():
    if len(queue) == 0:
        print("Queue is empty")
        return
    print("Removed:", queue.pop(0))  # remove from the front

def peek():
    if len(queue) == 0:
        print("Queue is empty")
    else:
        print("Front value:", queue[0])

enqueue(10)
enqueue(20)
enqueue(30)
peek()      # 10
dequeue()   # 10
dequeue()   # 20
peek()      # 30
