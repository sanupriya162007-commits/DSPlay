// Graph with an adjacency matrix: BFS (uses a queue) and DFS (uses recursion)
#include <stdio.h>

#define N 5                    // vertices 0..4  (0=A, 1=B, 2=C, 3=D, 4=E)

int graph[N][N];               // graph[a][b] = 1 means a and b are connected
int visited[N];

void addEdge(int a, int b) {
    graph[a][b] = 1;
    graph[b][a] = 1;           // undirected: connect both ways
}

void bfs(int start) {
    int queue[N], front = 0, rear = 0;
    for (int i = 0; i < N; i++) visited[i] = 0;

    queue[rear++] = start;     // put start in the queue
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];            // take from the front
        printf("%c ", 'A' + v);
        for (int next = 0; next < N; next++) {
            if (graph[v][next] && !visited[next]) {
                visited[next] = 1;
                queue[rear++] = next;      // add neighbours to the back
            }
        }
    }
    printf("\n");
}

void dfs(int v) {
    visited[v] = 1;
    printf("%c ", 'A' + v);
    for (int next = 0; next < N; next++) {
        if (graph[v][next] && !visited[next]) dfs(next);   // go deep first
    }
}

int main() {
    addEdge(0, 1);   // A-B
    addEdge(0, 2);   // A-C
    addEdge(1, 3);   // B-D
    addEdge(2, 4);   // C-E

    printf("BFS from A: ");
    bfs(0);

    for (int i = 0; i < N; i++) visited[i] = 0;
    printf("DFS from A: ");
    dfs(0);
    printf("\n");
    return 0;
}
