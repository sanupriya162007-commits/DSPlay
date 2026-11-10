#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node{int key;Node*left=nullptr,*right=nullptr;Node(int x):key(x){}};
Node* insert(Node*r,int x){if(!r)return new Node(x);if(x<r->key)r->left=insert(r->left,x);else if(x>r->key)r->right=insert(r->right,x);return r;}
Node* minimum(Node*r){while(r&&r->left)r=r->left;return r;}
Node* erase(Node*r,int x){if(!r)return nullptr;if(x<r->key)r->left=erase(r->left,x);else if(x>r->key)r->right=erase(r->right,x);else{if(!r->left){Node*t=r->right;delete r;return t;}if(!r->right){Node*t=r->left;delete r;return t;}Node*t=minimum(r->right);r->key=t->key;r->right=erase(r->right,t->key);}return r;}
bool search(Node*r,int x){while(r){if(r->key==x)return true;r=x<r->key?r->left:r->right;}return false;}
void inorder(Node*r){if(r){inorder(r->left);cout<<r->key<<' ';inorder(r->right);}}
struct Graph{vector<vector<int>> a;void addVertex(){a.emplace_back();}void addEdge(int u,int v){if(u>=0&&v>=0&&u<(int)a.size()&&v<(int)a.size()&&u!=v){a[u].push_back(v);a[v].push_back(u);}}void deleteEdge(int u,int v){if(u<0||v<0||u>=a.size()||v>=a.size())return;auto rem=[](vector<int>&x,int y){x.erase(remove(x.begin(),x.end(),y),x.end());};rem(a[u],v);rem(a[v],u);}bool searchVertex(int v){return v>=0&&v<a.size();}void deleteVertex(int v){if(!searchVertex(v))return;a.erase(a.begin()+v);for(auto&row:a)for(int&x:row)if(x>v)--x;for(auto&row:a)row.erase(remove(row.begin(),row.end(),v),row.end());}void bfs(int s){if(!searchVertex(s))return;vector<bool>seen(a.size());queue<int>q;q.push(s);seen[s]=true;while(!q.empty()){int v=q.front();q.pop();cout<<v<<' ';for(int n:a[v])if(!seen[n])seen[n]=true,q.push(n);}cout<<'\n';}void dfsRun(int v,vector<bool>&seen){seen[v]=true;cout<<v<<' ';for(int n:a[v])if(!seen[n])dfsRun(n,seen);}void dfs(int s){if(searchVertex(s)){vector<bool>seen(a.size());dfsRun(s,seen);}cout<<'\n';}};
int main(){Node*r=nullptr;for(int x:{50,30,70,20})r=insert(r,x);cout<<"BST: ";inorder(r);cout<<"\nSearch 30: "<<search(r,30)<<'\n';r=erase(r,30);cout<<"After delete: ";inorder(r);cout<<'\n';Graph g;g.addVertex();g.addVertex();g.addVertex();g.addEdge(0,1);g.addEdge(1,2);cout<<"BFS: ";g.bfs(0);cout<<"DFS: ";g.dfs(0);g.deleteEdge(0,1);g.deleteVertex(2);cout<<"Vertex 1 exists: "<<g.searchVertex(1)<<'\n';}
