import java.util.*;

public class TreeGraphDemo {
    static class Node { int key; Node left,right; Node(int k){key=k;} }
    static class BST {
        Node root;
        Node insert(Node n,int x){if(n==null)return new Node(x);if(x<n.key)n.left=insert(n.left,x);else if(x>n.key)n.right=insert(n.right,x);return n;}
        boolean search(int x){Node n=root;while(n!=null){if(n.key==x)return true;n=x<n.key?n.left:n.right;}return false;}
        Node min(Node n){while(n.left!=null)n=n.left;return n;}
        Node delete(Node n,int x){if(n==null)return null;if(x<n.key)n.left=delete(n.left,x);else if(x>n.key)n.right=delete(n.right,x);else{if(n.left==null)return n.right;if(n.right==null)return n.left;Node s=min(n.right);n.key=s.key;n.right=delete(n.right,s.key);}return n;}
        void inorder(Node n){if(n!=null){inorder(n.left);System.out.print(n.key+" ");inorder(n.right);}}
    }
    static class Graph {
        List<Set<Integer>> adj=new ArrayList<>();
        void addVertex(){adj.add(new LinkedHashSet<>());}
        void addEdge(int a,int b){if(valid(a)&&valid(b)&&a!=b){adj.get(a).add(b);adj.get(b).add(a);}}
        void deleteEdge(int a,int b){if(valid(a)&&valid(b)){adj.get(a).remove(b);adj.get(b).remove(a);}}
        boolean searchVertex(int v){return valid(v);} boolean valid(int v){return v>=0&&v<adj.size();}
        void deleteVertex(int v){if(!valid(v))return;adj.remove(v);for(Set<Integer> row:adj){Set<Integer> next=new LinkedHashSet<>();for(int x:row){if(x!=v)next.add(x>v?x-1:x);}row.clear();row.addAll(next);}}
        List<Integer> bfs(int start){List<Integer> out=new ArrayList<>();if(!valid(start))return out;boolean[] seen=new boolean[adj.size()];Queue<Integer>q=new ArrayDeque<>();q.add(start);seen[start]=true;while(!q.isEmpty()){int v=q.remove();out.add(v);for(int n:adj.get(v))if(!seen[n]){seen[n]=true;q.add(n);}}return out;}
        void dfsVisit(int v,boolean[]seen,List<Integer>out){seen[v]=true;out.add(v);for(int n:adj.get(v))if(!seen[n])dfsVisit(n,seen,out);}
        List<Integer> dfs(int start){List<Integer>out=new ArrayList<>();if(valid(start))dfsVisit(start,new boolean[adj.size()],out);return out;}
    }
    public static void main(String[] args){BST t=new BST();for(int x:new int[]{50,30,70,20})t.root=t.insert(t.root,x);System.out.print("BST inorder: ");t.inorder(t.root);System.out.println("\nSearch 30: "+t.search(30));t.root=t.delete(t.root,30);System.out.print("After delete: ");t.inorder(t.root);Graph g=new Graph();g.addVertex();g.addVertex();g.addVertex();g.addEdge(0,1);g.addEdge(1,2);System.out.println("\nBFS: "+g.bfs(0));System.out.println("DFS: "+g.dfs(0));g.deleteEdge(0,1);g.deleteVertex(2);System.out.println("Vertex 1 exists: "+g.searchVertex(1));}
}
