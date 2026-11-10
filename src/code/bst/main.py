# Binary Search Tree: insert, search, inorder
# Rule: smaller values go LEFT, larger values go RIGHT

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(root, value):
    if root is None:
        return Node(value)               # found an empty spot
    if value < root.data:
        root.left = insert(root.left, value)
    elif value > root.data:
        root.right = insert(root.right, value)
    return root

def search(root, value):
    if root is None:
        return False                     # not found
    if value == root.data:
        return True                      # found
    if value < root.data:
        return search(root.left, value)
    return search(root.right, value)

def inorder(root):                       # left, root, right
    if root is None:
        return
    inorder(root.left)
    print(root.data, end=" ")
    inorder(root.right)

root = None
for number in [50, 30, 70, 20, 40]:
    root = insert(root, number)

print("Inorder: ", end="")
inorder(root)                            # 20 30 40 50 70
print()
print("Search 40:", "Found" if search(root, 40) else "Not found")
print("Search 99:", "Found" if search(root, 99) else "Not found")
