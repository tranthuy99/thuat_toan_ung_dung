#include<iostream>
#include<list>
using namespace std;

int *color;

class Tree{
	int v; 
	list<int> *adj;
	public:
		Tree(int v);
		void addEdge(int v, int u);
		bool checkBipartie(int u);
};

Tree::Tree(int v){
	this->v=v;
	adj=new list<int>[v+1];
}

void Tree::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool Tree::checkBipartie(int u){
	list<int>::iterator i;//cout<<"aaa";
	for (i=adj[u].begin(); i!=adj[u].end(); i++){
		int v=*i;
		if (color[v]==-1){
			color[v]=1-color[u];
			checkBipartie(v);
		}else if (color[v]==color[u]) return false;
		
	}
	return true;
}

int main(){
	int n, m; 
	cin>>n>>m;
	Tree g(n);
	for (int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		g.addEdge(a, b);
	}
	color=new int[n+1];
	for (int i=1; i<=n; i++)  color[i]=-1;
	
	for (int i=1; i<=n; i++){
		if (color[i]==-1){
			color[i]=0;
			if (!g.checkBipartie(i)) {
			cout<<0;
			return 0;
		}
		
		}
	}
	
    cout<<1;
    return 0;
}
