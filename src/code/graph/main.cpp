// Graph with an adjacency matrix: BFS (uses a queue) and DFS (uses recursion)
#include <iostream>
#include <queue>
using namespace std;

const int N = 5;               // vertices 0..4  (0=A, 1=B, 2=C, 3=D, 4=E)
int graph[N][N];               // graph[a][b] = 1 means a and b are connected
bool visited[N];

void addEdge(int a, int b) {
    graph[a][b] = 1;
    graph[b][a] = 1;           // undirected: connect both ways
}

void bfs(int start) {
    queue<int> q;
    for (int i = 0; i < N; i++) visited[i] = false;

    q.push(start);             // put start in the queue
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();     // take from the front
        q.pop();
        cout << char('A' + v) << " ";
        for (int next = 0; next < N; next++) {
            if (graph[v][next] && !visited[next]) {
                visited[next] = true;
                q.push(next);  // add neighbours to the back
            }
        }
    }
    cout << endl;
}

void dfs(int v) {
    visited[v] = true;
    cout << char('A' + v) << " ";
    for (int next = 0; next < N; next++) {
        if (graph[v][next] && !visited[next]) dfs(next);   // go deep first
    }
}

int main() {
    addEdge(0, 1);   // A-B
    addEdge(0, 2);   // A-C
    addEdge(1, 3);   // B-D
    addEdge(2, 4);   // C-E

    cout << "BFS from A: ";
    bfs(0);

    for (int i = 0; i < N; i++) visited[i] = false;
    cout << "DFS from A: ";
    dfs(0);
    cout << endl;
    return 0;
}
