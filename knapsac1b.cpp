#include<iostream>
using namespace std;

main(){
	int n, b;
	cin>>n>>b;
	int *a=new int[n];
	int *c=new int[n];
	for(int i=0; i<n; i++)
	  cin>>a[i]>>c[i];
	int res=0;
	
	for(int mask=1<<n; mask>=0; mask--){
		int m=0,f=0;
		for (int i=0; i<n; i++){
			if (mask>>i&1) {
				m=m+a[i];
				f=f+c[i];
			}
			if (m>b) {
				f=0;
			}
		}
		res=max(res, f);
	}
	cout<<res;
}
