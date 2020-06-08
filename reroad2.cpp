#include<iostream>
#include<stdlib.h>
using namespace std;

main(){
	int n;

	int q;
	cin>>n;
	int *t=(int*)malloc(n*sizeof(int));
	int *b=(int*)malloc(n*sizeof(int));
	for (int i=0; i<n; i++)
	cin>>t[i];
	int ans=1;
	b[0]=1;
	for (int i=1; i<n; i++)
	if (t[i]!=t[i-1]) {
		ans++;
		b[i]=1;
	}
	else b[i]=0;
	cin>>q;
	while(q--){
		int p;
		cin>>p;
		cin>>t[p-1];
		if (n==1) cout<<1<<endl;
		else{
		    
		if (p==1) {
			ans=ans-b[1];
			if (t[0]==t[1]) b[1]=0;
			else b[1]=1;
			ans=ans+b[1];
		}
		else if (p==n) {
			ans=ans-b[n-1];
			if (t[n-2]==t[n-1]) b[n-1]=0;
			else b[n-1]=1;
			ans=ans+b[n-1];
		}
		else {
			ans=ans-b[p-1]-b[p];
			if (t[p-1]==t[p-2]) b[p-1]=0;
			else b[p-1]=1;
			if (t[p]==t[p-1]) b[p]=0;
			else b[p]=1;
			ans=ans+b[p-1]+b[p];
		}
		cout<<ans<<endl;}
	}

}
