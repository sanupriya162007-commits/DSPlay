# Graph with an adjacency list: BFS (uses a queue) and DFS (uses recursion)

graph = {
    "A": ["B", "C"],
    "B": ["A", "D"],
    "C": ["A", "E"],
    "D": ["B"],
    "E": ["C"],
}

def bfs(start):
    visited = [start]
    queue = [start]                    # put start in the queue
    while len(queue) > 0:
        v = queue.pop(0)               # take from the front
        print(v, end=" ")
        for neighbour in graph[v]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)    # add neighbours to the back
    print()

visited_dfs = []

def dfs(v):
    visited_dfs.append(v)
    print(v, end=" ")
    for neighbour in graph[v]:
        if neighbour not in visited_dfs:
            dfs(neighbour)             # go deep first

print("BFS from A: ", end="")
bfs("A")
print("DFS from A: ", end="")
dfs("A")
print()
