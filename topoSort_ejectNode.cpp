#include<iostream>
#include<queue>
#include<list>
#include<vector>
using namespace std;


class Graph{
	int V;
	list<int> *adj;
	
	public:
		int *indeg;
		Graph(int v);
		int getV();
		void addEdge(int u, int v);
		void topo_Eject();
};

Graph::Graph(int v){
	this->V=v;
	adj=new list<int>[v];
	indeg=new int[v];
	for (int i=0; i<v; i++) indeg[i]=0;
}

int Graph::getV(){
	return this->V;
}
void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	indeg[v]++;
}
 
void Graph::topo_Eject(){
	list<int> result;
	queue<int> Q;
	int V=this->V;//cout<<indeg[0];
	for (int i=0; i<V; i++){
		if (indeg[i]==0) {
		//	cout<<i<<"aaaa";
		Q.push(i);
		}
	}
	int num=0;
	while (!Q.empty()){
		int v=Q.front();
		Q.pop();
		num++;
		result.push_back(v);
		list<int>::iterator i;
		for (i=adj[v].begin(); i!=adj[v].end(); i++){
			indeg[*i]--;
			if (indeg[*i]==0)  Q.push(*i);
		}
		
	}
	if (num!=V){
	    cout<<num<<endl;
		cout<<"Do thi co chu trinh\n";
		return;
	}
	
	list<int>::iterator i;
	for (i=result.begin(); i!=result.end(); i++){
		cout<<*i<<" ";
	}
}

main(){
	Graph g(10);
	g.addEdge(0, 1);g.addEdge(0, 4);g.addEdge(0, 6);
	g.addEdge(1, 2);g.addEdge(2, 5);g.addEdge(2, 7);
	g.addEdge(3, 4);g.addEdge(3, 8);g.addEdge(4, 5);
	g.addEdge(6, 2); g.addEdge(6, 3);g.addEdge(7, 8);
	g.addEdge(9, 6);//cout<<g.indeg[0];
	g.topo_Eject();
}
