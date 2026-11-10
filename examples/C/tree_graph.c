/* Binary Search Tree + undirected Graph operations: insert, delete, search, BFS, DFS */
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct Node { int key; struct Node *left, *right; } Node;
Node *newNode(int x){ Node *n=(Node*)malloc(sizeof(Node)); n->key=x; n->left=n->right=NULL; return n; }
Node *insert(Node *r,int x){ if(!r)return newNode(x); if(x<r->key)r->left=insert(r->left,x); else if(x>r->key)r->right=insert(r->right,x); return r; }
Node *minimum(Node *r){ while(r&&r->left)r=r->left; return r; }
Node *deleteKey(Node *r,int x){ if(!r)return NULL; if(x<r->key)r->left=deleteKey(r->left,x); else if(x>r->key)r->right=deleteKey(r->right,x); else { if(!r->left){Node*t=r->right;free(r);return t;} if(!r->right){Node*t=r->left;free(r);return t;} Node*t=minimum(r->right);r->key=t->key;r->right=deleteKey(r->right,t->key);} return r; }
int search(Node*r,int x){while(r){if(x==r->key)return 1;r=x<r->key?r->left:r->right;}return 0;}
void inorder(Node*r){if(r){inorder(r->left);printf("%d ",r->key);inorder(r->right);}}
int graph[MAX][MAX], vertices=0;
void addVertex(void){if(vertices<MAX){vertices++;printf("Added vertex %d\n",vertices-1);}else puts("Graph is full");}
void addEdge(int a,int b){if(a>=0&&b>=0&&a<vertices&&b<vertices&&a!=b)graph[a][b]=graph[b][a]=1;else puts("Invalid vertices");}
void deleteEdge(int a,int b){if(a>=0&&b>=0&&a<vertices&&b<vertices)graph[a][b]=graph[b][a]=0;}
void deleteVertex(int v){if(v<0||v>=vertices)return;for(int i=0;i<vertices;i++)graph[v][i]=graph[i][v]=0;for(int i=v;i<vertices-1;i++)for(int j=0;j<vertices;j++)graph[i][j]=graph[i+1][j];for(int i=0;i<vertices-1;i++)for(int j=v;j<vertices-1;j++)graph[i][j]=graph[i][j+1];vertices--;}
int searchVertex(int v){return v>=0&&v<vertices;}
void bfs(int start){int q[MAX],front=0,rear=0,seen[MAX]={0};if(!searchVertex(start))return;q[rear++]=start;seen[start]=1;while(front<rear){int v=q[front++];printf("%d ",v);for(int i=0;i<vertices;i++)if(graph[v][i]&&!seen[i]){seen[i]=1;q[rear++]=i;}}puts("");}
void dfsVisit(int v,int seen[]){seen[v]=1;printf("%d ",v);for(int i=0;i<vertices;i++)if(graph[v][i]&&!seen[i])dfsVisit(i,seen);}
void dfs(int start){int seen[MAX]={0};if(searchVertex(start))dfsVisit(start,seen);puts("");}
int main(void){Node *root=NULL;root=insert(root,50);root=insert(root,30);root=insert(root,70);root=insert(root,20);printf("BST inorder: ");inorder(root);puts("");printf("Search 30: %s\n",search(root,30)?"found":"not found");root=deleteKey(root,30);printf("After delete 30: ");inorder(root);puts("");addVertex();addVertex();addVertex();addEdge(0,1);addEdge(1,2);printf("BFS: ");bfs(0);printf("DFS: ");dfs(0);deleteEdge(0,1);printf("Search vertex 2: %s\n",searchVertex(2)?"found":"not found");deleteVertex(2);return 0;}
