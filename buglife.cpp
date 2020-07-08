#include<iostream>
#include<list>
using namespace std;


class Graph{
	int v;
	list<int> *adj;
	public:
		int *color;
		//int getnum();
		void addEdge(int u, int v);
		Graph(int v);
		void checkBugs(int v);
		bool dfs(int i);
};

Graph::Graph(int v){
	this->v=v;
	adj=new list<int>[v+1];
	color=new int[v+1];
	for (int i=1; i<=v; i++)  color[i]=-1;
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool Graph::dfs(int u){
	list<int>::iterator i;
	for (i=adj[u].begin(); i!=adj[u].end(); i++){
		if (color[*i]==-1) {
			color[*i]=1-color[u];
			dfs(*i);
		}else if (color[*i]==color[u])  return false;
	}
	return true;
}

void Graph::checkBugs(int v){
	for (int i=1; i<=v; i++){
		if (color[i]==-1){
			color[i]=0;
			if (!dfs(i)) {
				cout<<"Suspicious bugs found!\n";
				return;
			}
			
		} 
	}
    cout<<"No suspicious bugs found!\n";
    return;
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for (int i=0; i<t; i++){
		int n, m;
		cin>>n>>m;
		Graph g(n+1);
		for (int j=0; j<m; j++){
			int a, b;
			cin>>a>>b;
			g.addEdge(a, b);
			
		}
		cout<<"Scenario #"<<i+1<<":\n";
		g.checkBugs(n);
	}
}

