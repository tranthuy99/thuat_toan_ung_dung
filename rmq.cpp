#include<iostream>
using namespace std;

main(){
	int n;
	cin>>n; int *a=new int [n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int m;
	cin>>m;
	int res=0;
	for(int i=0; i<m; i++){
		int t1,t2;
		cin>>t1>>t2;
		int minn=a[t1];
		for(int j=t1+1; j<=t2; j++)
		minn=min(minn, a[j]);
		res=res+minn;
	}
	cout<<res;
}
