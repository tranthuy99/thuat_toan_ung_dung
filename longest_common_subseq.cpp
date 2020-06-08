#include<iostream>
#include<stdlib.h>
using namespace std;


main(){

	//cout<<"MMMM";
	int n, m;
	cin>>n>>m;
	int **l = new int*[m+1];
for(int i = 0; i<=m; i++)
   l[i] = new int[n+1];
	int *a=new int[n+1];
	int *b=new int [m+1];
	for (int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=m; i++)  cin>>b[i];
	//cout<<"MMMM";
	for(int i=0; i<=n; i++) l[0][i]=0;//cout<<"MMMM";
	for(int i=0; i<=m; i++) l[i][0]=0;
	for (int i=1; i<=m; i++)
	
	for(int j=1; j<=n; j++){//cout<<"MMMM";
		if(b[i]==a[j]) l[i][j]=l[i-1][j-1]+1;
		else l[i][j]=max(l[i-1][j], l[i][j-1]);
	}
	cout<<l[m][n];
}
