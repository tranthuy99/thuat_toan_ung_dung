#include<iostream>
#include<list>
#include<vector>
using namespace std;

int *visited;
int *fore;

class Graph{
	int v; 
	list<int> *adj;
	public:
		int getV();
		void addEdge(int v, int u);
		void dfs(int s);
		Graph(int v);
};
Graph::Graph(int v){
	this->v=v;
	adj=new list<int>[v];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}
void Graph::dfs(int s){
	visited[s]=1;
	list<int>::iterator i;
	for (i=adj[s].begin(); i!=adj[s].end(); i++){
		if (visited[*i]==0){
			fore[*i]=s;
			dfs(*i);
		}
	}
}

int Graph::getV(){
	return this->v;
}

main(){
	Graph g(5);
	g.addEdge(0, 2);
	g.addEdge(1,2);
	g.addEdge(1, 3);
	g.addEdge(3, 0);
	g.addEdge(2, 4);
	int s, t;
	cout<<"Nhap vao s, t ";
	cin>>s>>t;
	int v=g.getV();
	visited=new int[v];
	fore=new int[v];
	for(int i=0; i<v; i++){
		visited[i]=0;
		fore[i]=-1;
	}
	g.dfs(s);
	if (fore[t]!=-1) {
		vector<int> l;
		while (t!=-1){
			//cout<<t;
			l.push_back(t);
			t=fore[t];
		}
		//cout<<l.size();
		for (int i=l.size()-1; i>=0; i--){
			cout<<l[i]<<" ";;
		}
	}
	else cout<<"K co duong di";
}
