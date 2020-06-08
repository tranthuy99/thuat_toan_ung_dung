#include<iostream>
using namespace std;

int f=9999999;
int g=0;
int cmin=9999999;
int t[25];
int c[25][25];
int visited[25];
int n, m, g1;
void TSP(int k){
	for (int v=1; v<n; v++){
		if (visited[v]==0&&c[t[k-1]][v]!=0){
			t[k]=v;
			visited[v]=1;
			g=g+c[t[k-1]][t[k]];
			if (k==(n-1)&&c[t[n-1]][0]){
				if (g+c[t[n-1]][t[0]]<f) f=g+c[t[n-1]][t[0]];
			}else {
				g1=g+(n-k+1)*cmin;
				if (g1<f) TSP(k+1);
			}
			visited[v]=0;
			g=g-c[t[k-1]][t[k]];
		}
	}
}
main(){
	
	cin>>n>>m;
	for (int i=0; i<n; i++)
	for (int j=0; j<n; j++)
	c[i][j]=0;
	while (m--){
		int i, j;
		cin>>i>>j;
		cin>>c[i-1][j-1];
	}
	
	for (int i=0; i<n; i++)
	for (int j=0; j<n; j++)
	if (cmin>c[i][j]&&c[i][j]>0) cmin=c[i][j];
	cout<<cmin;
	for (int i=0; i<n; i++) {
		visited[i]=0;
		//t[i]=i;
	}
	t[0]=0;
	TSP(1);
	cout<<f;
}
