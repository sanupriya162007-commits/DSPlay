# DS Play — interactive data structures learning prototype

A React + Vite learning website with beginner explanations, visual step traces, browser voice narration, and a sequential practice path.

## Run locally

1. Install Node.js (LTS).
2. Extract this folder and open it in VS Code.
3. Open a terminal in this folder.
4. Run:

```bash
npm install
npm run dev
```

5. Open the local URL printed by Vite.

To create a production build:

```bash
npm run build
npm run preview
```

## Code panel (beginner examples)

Each topic shows a short, commented beginner program in C, C++, Python and Java.
The examples are normal files in `src/code/<topic>/` (`main.c`, `main.cpp`, `main.py`, `Main.java`).
To change an example, just edit that file. To point a topic at a different example, edit `codeTopics` in `src/App.jsx`.

## Main features

- Beginner-first explanations for every topic.
- Empty simulator canvas until the learner enters data and executes an operation.
- Voice narration for the currently selected step. The Voice ON/OFF control uses the browser Speech Synthesis API.
- Step navigation with Previous and Next.
- Infix-to-postfix conversion with precedence and parenthesis handling.
- Postfix expression evaluation using an operand stack.
- BFS and DFS graph traversal.
- Stack, queue, linked-list, searching, sorting, hashing, merge, and Tower of Hanoi demonstrations.
- A sequential practice map. A topic is marked explored after a successful simulation; the next checkpoint unlocks.
- Progress and display name saved in browser localStorage.

## Supported demo input examples

| Topic | Example |
|---|---|
| Stack | Enter `10`, choose Push; repeat with `20`, then Pop |
| Queue | Enter `10`, Enqueue; then enter `20`, Enqueue; Dequeue |
| Infix to Postfix | `A+B*C` or `(A+B)*C` |
| Postfix evaluation | `5 2 3 * +` |
| Graph traversal | Choose BFS or DFS; the demo graph starts at A |
| Tower of Hanoi | `3` |
| Linear search | Values `8, 3, 6, 1`; target `6` |
| Binary search | Sorted values `1, 3, 6, 8, 10`; target `8` |
| Bubble / Shell sort | `8, 3, 6, 1, 5` |
| Hashing | `10, 17, 24, 31` |
| Multiway merge | `1,4;2,5;3,6` |

## Important engineering scope

This is a client-side educational prototype, not a production compiler or a complete algorithm visualisation framework. The core infix/postfix, graph traversal, search, sorting, hashing collision, and Hanoi demonstrations execute locally. Some advanced structures (notably AVL rotations and full B-tree node splitting) are currently explanatory insertion demonstrations rather than complete production-grade implementations. External and polyphase merge are simplified teaching flows, not actual disk-file I/O. The AI Tutor uses local rule-based explanations; no remote AI service is connected.

Voice availability and voice quality depend on the browser and installed system voices. The app needs browser speech synthesis support for narration.

## Updates in this build

- Voice narration now advances automatically: it speaks the current step, waits for that utterance to finish, advances the visual frame, and continues until the final step. Turning Voice OFF stops narration; the student can still use Previous / Next manually. The existing browser speech voice and speaking rate setting are preserved.
- Binary Tree, Binary Search Tree, AVL Tree, and B-tree simulator controls now include Insert, Delete, and Search. Binary-tree deletion uses the deepest/rightmost replacement demonstration; search-tree deletion demonstrates removing the key and rebuilding the remaining values for this teaching view.
- Graph Traversals now starts with an empty graph. Add vertices using labels such as `A`, add undirected edges using `A-B`, delete vertices or edges, search for a vertex, and run BFS or DFS from a starting vertex. The graph canvas displays vertices, edges, and visited nodes.
- Standalone reference implementations for BST operations and graph operations (insert/add, delete, search, BFS, DFS) are included in `examples/C`, `examples/Cpp`, `examples/Python`, and `examples/Java`.

## Run the language examples

- C: `gcc examples/C/tree_graph.c -o tree_graph && ./tree_graph`
- C++: `g++ examples/Cpp/tree_graph.cpp -o tree_graph && ./tree_graph`
- Python: `python examples/Python/tree_graph.py`
- Java: `javac examples/Java/TreeGraphDemo.java && java -cp examples/Java TreeGraphDemo`

These four-language examples cover the requested core tree and graph operations. The remaining topics still use the in-app visual logic guide; their complete language-specific source listings are not yet included in this prototype.


## Source code panel update

The Simulator page now includes a language selector for C, C++, Python, and Java. It displays runnable reference source code beside the visual step tutor. The current in-app code panel provides complete BST (insert/search/delete/inorder) and graph (add edge/BFS/DFS) examples in all four languages. For other topics, the panel clearly identifies that the topic-specific code listing is not yet implemented; it does not pretend that the BST/graph sample is the code for an unrelated algorithm.
