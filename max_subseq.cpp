#include<iostream>
using namespace std;

main(){
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0; i<n; i++)
	cin>>a[i];
	int *f=new int[n];
	int res=a[0];
	f[0]=a[0];
	for (int i=1; i<n; i++){
		f[i]=max(a[i], f[i-1]+a[i]);
		res=max(res, f[i]);
	}
	cout<<res;
}
