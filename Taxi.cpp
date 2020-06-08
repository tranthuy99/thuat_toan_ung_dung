#include<iostream>
#include<algorithm>
using namespace std;
int n, g1;

int f=99999999;

int c[100][100];
int t[100];





main(){
	cin>>n;
	int m=2*n;
	for (int i=0; i<=m; i++){
		t[i]=i;
		for (int j=0; j<=m; j++)
	{
		cin>>c[i][j];
	}
	}
	
    do{ 
        int g=0;    
		g=g+c[0][t[1]]+c[t[1]][t[1]+n];
		for (int i=2; i<=n; i++){
			g1=c[t[i-1]+n][t[i]]+c[t[i]][t[i]+n];
			g=g+g1;
		}
		if (g+c[t[n]+n][0]<f)  f=g+c[t[n]+n][0];
	}	while(std::next_permutation(t+1,t+n+1));
	cout<<f;
}
