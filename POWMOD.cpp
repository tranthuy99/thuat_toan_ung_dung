#include<iostream>
using namespace std;

long long powmod(long long a, long long b,long long p){
	long long ans=1;
	long long c=a*a%p;
	for (long long i=b; i>0; i-=2){
		
		if (i==1) ans=ans*a%p;
		else {
			
		ans=ans*c%p;
		}
	}
	return ans;
}

main(){
	long long a, b, p=1000000007;
	cin>>a>>b;
	a=a%p;
	b=b%(p-1);
	cout<<powmod(a,b,p);
}
