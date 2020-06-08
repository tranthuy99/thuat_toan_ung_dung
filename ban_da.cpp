#include <iostream>
#include<stdlib.h>
using namespace std;

main(){
	long long n;
	cin>>n;
	
	while(n!=0){
		long long smax=0;
		long long *a=(long long *)malloc(n*sizeof(long long));
		long long *s=(long long *)malloc(n*sizeof(long long ));
		for (long long i=0; i<n ; i++){
			cin>>a[i];
			s[i]=a[i];
		}
		for (long long i=0; i<n ; i++){
			if (a[i]!=0){
				for (long long j=i-1; j>=0; j--)
			    if (a[j]>=a[i]) s[i]+=a[i];
			    else break;
			for (long long j=i+1; j<n; j++)
			    if (a[j]>=a[i])  s[i]+=a[i];
			    else break;
			} 
			
			if (smax<s[i]) smax=s[i];
		}
		cout<<smax<<endl;
		cin>>n;
	}
}
