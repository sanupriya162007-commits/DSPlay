// Graph with an adjacency matrix: BFS (uses a queue) and DFS (uses recursion)
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static final int N = 5;                    // vertices 0..4  (0=A, 1=B, 2=C, 3=D, 4=E)
    static int[][] graph = new int[N][N];      // graph[a][b] = 1 means a and b are connected
    static boolean[] visited = new boolean[N];

    static void addEdge(int a, int b) {
        graph[a][b] = 1;
        graph[b][a] = 1;                       // undirected: connect both ways
    }

    static void bfs(int start) {
        Queue<Integer> queue = new LinkedList<>();
        visited = new boolean[N];

        queue.add(start);                      // put start in the queue
        visited[start] = true;

        while (!queue.isEmpty()) {
            int v = queue.remove();            // take from the front
            System.out.print((char) ('A' + v) + " ");
            for (int next = 0; next < N; next++) {
                if (graph[v][next] == 1 && !visited[next]) {
                    visited[next] = true;
                    queue.add(next);           // add neighbours to the back
                }
            }
        }
        System.out.println();
    }

    static void dfs(int v) {
        visited[v] = true;
        System.out.print((char) ('A' + v) + " ");
        for (int next = 0; next < N; next++) {
            if (graph[v][next] == 1 && !visited[next]) dfs(next);   // go deep first
        }
    }

    public static void main(String[] args) {
        addEdge(0, 1);   // A-B
        addEdge(0, 2);   // A-C
        addEdge(1, 3);   // B-D
        addEdge(2, 4);   // C-E

        System.out.print("BFS from A: ");
        bfs(0);

        visited = new boolean[N];
        System.out.print("DFS from A: ");
        dfs(0);
        System.out.println();
    }
}
