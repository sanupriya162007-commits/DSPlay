"""Binary Search Tree and undirected Graph: insert, delete, search, BFS, DFS."""
from collections import deque

class Node:
    def __init__(self, key): self.key, self.left, self.right = key, None, None

class BST:
    def __init__(self): self.root = None
    def insert(self, key):
        def add(node):
            if node is None: return Node(key)
            if key < node.key: node.left = add(node.left)
            elif key > node.key: node.right = add(node.right)
            return node
        self.root = add(self.root)
    def search(self, key):
        node = self.root
        while node:
            if key == node.key: return True
            node = node.left if key < node.key else node.right
        return False
    def delete(self, key):
        def remove(node, value):
            if node is None: return None
            if value < node.key: node.left = remove(node.left, value)
            elif value > node.key: node.right = remove(node.right, value)
            else:
                if node.left is None: return node.right
                if node.right is None: return node.left
                successor = node.right
                while successor.left: successor = successor.left
                node.key = successor.key
                node.right = remove(node.right, successor.key)
            return node
        self.root = remove(self.root, key)
    def inorder(self):
        result = []
        def walk(node):
            if node: walk(node.left); result.append(node.key); walk(node.right)
        walk(self.root); return result

class Graph:
    def __init__(self): self.adj = {}
    def add_vertex(self, v): self.adj.setdefault(v, set())
    def add_edge(self, a, b):
        if a not in self.adj or b not in self.adj: raise ValueError("Add both vertices first")
        self.adj[a].add(b); self.adj[b].add(a)
    def delete_edge(self, a, b): self.adj.get(a, set()).discard(b); self.adj.get(b, set()).discard(a)
    def delete_vertex(self, v):
        if v in self.adj:
            for neighbour in list(self.adj[v]): self.adj[neighbour].discard(v)
            del self.adj[v]
    def search(self, v): return v in self.adj
    def bfs(self, start):
        if start not in self.adj: return []
        order, seen, queue = [], {start}, deque([start])
        while queue:
            v = queue.popleft(); order.append(v)
            for n in sorted(self.adj[v]):
                if n not in seen: seen.add(n); queue.append(n)
        return order
    def dfs(self, start):
        if start not in self.adj: return []
        order, seen, stack = [], set(), [start]
        while stack:
            v = stack.pop()
            if v in seen: continue
            seen.add(v); order.append(v)
            stack.extend(sorted(self.adj[v], reverse=True))
        return order

if __name__ == "__main__":
    tree = BST()
    for value in (50, 30, 70, 20): tree.insert(value)
    print("BST inorder:", tree.inorder())
    print("Search 30:", tree.search(30))
    tree.delete(30); print("After delete:", tree.inorder())
    graph = Graph()
    for vertex in "ABC": graph.add_vertex(vertex)
    graph.add_edge("A", "B"); graph.add_edge("B", "C")
    print("BFS:", graph.bfs("A")); print("DFS:", graph.dfs("A"))
    graph.delete_edge("A", "B"); graph.delete_vertex("C")
    print("Search B:", graph.search("B"))
