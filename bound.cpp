#include<iostream>
#include<stdlib.h>
using namespace std;

main(){
	int n, m, M;
	
	cin>>n;
	cin>>m>>M;
	int ans=0;
	int *a=(int *) malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		int s=0;
		for(int j=i; j<n; j++)
		{ 
		s=s+a[j];
		if (s>=m&&s<=M) ans++;
		}
	}
	cout<<ans;
}
