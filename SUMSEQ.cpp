#include<iostream>
#include<stdlib.h>
using namespace std;

main(){
	int n;
	int p=1000000007;
	cin>>n;
	int *a=(int*)malloc(n*sizeof(int));
	for (int i=0; i<n ; i++ )
	cin>>a[i];
	int ans=0;
	for ( int i=0; i<n ; i++ ){
		ans=ans%p+a[i]%p;
	}
	cout<<ans;
}
