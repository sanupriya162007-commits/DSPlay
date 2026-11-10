# Singly linked list: insert at head, delete first node, print

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None      # link to the next node

head = None                   # None means the list is empty

def insert_at_head(value):
    global head
    new_node = Node(value)
    new_node.next = head      # new node points to the old first node
    head = new_node           # new node becomes the first node

def delete_first():
    global head
    if head is None:
        print("List is empty")
        return
    head = head.next          # move head to the second node

def print_list():
    current = head
    while current is not None:
        print(current.data, end=" -> ")
        current = current.next    # follow the link
    print("None")

insert_at_head(30)
insert_at_head(20)
insert_at_head(10)
print_list()     # 10 -> 20 -> 30 -> None
delete_first()
print_list()     # 20 -> 30 -> None
