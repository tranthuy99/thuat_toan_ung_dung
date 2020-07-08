#include<iostream>
#include<list>
#include<queue>
using namespace std;

int *visited;

class Graph{
	int v;
	list<int> *adj;
	
	public:
		//int getV();
		void addEgde(int v, int u);
		void dfs(int u);
		Graph(int v);
};

Graph::Graph(int v){
	this->v=v;
	adj=new list<int>[v+1];
}

void Graph::addEgde(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::dfs(int v){
	visited[v]=1;
	//cout<<v<<" ";
	list<int>::iterator i;
	for(i=adj[v].begin(); i!=adj[v].end(); i++){
		int u=*i;
		if (visited[u]==0){
			//visited[u]=1;
			dfs(u);
		}
	}
	//cout<<"aaaaaa";
}


main(){
	int n,m;
	cin>>n>>m;
	int count=0;
	Graph g(n);
	for (int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		g.addEgde(a, b);
	}

	visited=new int[n+1];
	for (int i=1; i<=n; i++)  visited[i]=0;
	
	for(int i=1; i<=n; i++){
		if (visited[i]==0)  {
			g.dfs(i);
			count++;
		}//cout<<"aaaaaa";
	}
	cout<<count;
}
