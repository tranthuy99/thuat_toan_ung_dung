#include<iostream>
using namespace std;

main(){
	int n, l1, l2;
	cin>>n>>l1>>l2;
	int *a=new int[n];
	for(int i=0; i<n; i++){
		cin>>a[i];		
	}
	int res=0;
	int *f=new int[n];
	for(int i=0; i<n; i++){
		f[i]=a[i];
		for(int j=max(0, i-l2); j<=i-l1; j++)
		    f[i]=max(f[i], a[i]+f[j]);
	    res=max(res, f[i]);
	}
	cout<<res;
	
}
