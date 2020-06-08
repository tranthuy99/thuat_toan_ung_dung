#include<iostream>
#include<math.h>
using namespace std;

main(){
	long long a, b;
	long long p=pow(10,9)+7;
	cout<<p;
	cin>>a>>b;
	a=a%p;
	b=b%p;
	long long c=p-a;
	if (b<c) cout<<a+b;
	else cout<<b-c;
}
