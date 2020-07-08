#include<iostream>
#include<stack>
#include<list>
using namespace std;

int *visited;
stack<int> st;

class Graph{
	int V;
	list<int> *adj;
	public:
		Graph(int V);
		void addEdge(int u, int v);
		int getV();
		void dfs(int u);
		void topoSort();
};

Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void Graph::dfs(int u){
	visited[u]=1;
	list<int>::iterator i;
	for(i=adj[u].begin(); i!=adj[u].end(); i++){
		if (visited[*i]==0) dfs(*i);
	}
	st.push(u);
}

int Graph::getV(){
	return this->V;
}

void Graph::topoSort(){
	for (int i=0; i<this->V; i++){
		visited[i]=0;
	}
	for (int i=0; i<this->V; i++){
		if (visited[i]==0)  dfs(i);
	}
	while(st.empty()==false){
		cout<<st.top()<<" ";
		st.pop();
	}
}

main(){
	Graph g(5);
	g.addEdge(0, 2);
	g.addEdge(1,2);
	g.addEdge(1, 3);
	g.addEdge(3, 0);
	g.addEdge(2, 4);
	int V=g.getV();
	visited=new int[V];
	g.topoSort();
}
