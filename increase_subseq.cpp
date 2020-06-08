#include<iostream>
using namespace std;

main(){
	int n;
	cin>>n;
	int *a=new int [n];
	for(int i=0; i<n; i++)
	  cin>>a[i];
	int *f=new int [n];
	f[0]=1;
	
	int res=1;
	for (int i=1; i<n; i++){
		int maxx=0; 
		for(int j=0; j<i; j++){
			if (a[j]<a[i]) maxx=max(maxx, f[j]);
		}
		f[i]=maxx+1;
		res=max(res, f[i]);
	}
	cout<<res;
}
