#include<iostream>
#include<list>
using namespace std;

class Tree{
	int node;
	
	public:
		list<int> *adj;
		Tree(int node);
		void addEdge(int u, int v);
};

Tree::Tree(int node){
	this->node=node;
	adj=new list<int>[node+1];
}

void Tree::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

main(){
	int n;
	cin>>n;
	int count=0;
	Tree g(n);
	for (int i=0; i<n-1; i++){
		int a, b;
		cin>>a>>b;
		g.addEdge(a, b);
	}
	for (int i=2; i<=n; i++)
	  if (g.adj[i].size()==1) count++;
	  cout<<count;
}
