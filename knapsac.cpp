#include<iostream>
using namespace std;

int n, b;
int a[40];
int c[40];
int result=0;

void xet(int i, int m, int val){
	if (i>n){
		if (val>result) result=val;
		return;
	}
	xet(i+1,  m, val);
	if (m+a[i]<=b)
	xet(i+1, m+a[i], val+c[i]);
}

main(){
	cin>>n>>b;
	for(int i=0; i<n; i++){
		cin>>a[i]>>c[i];
	}
	xet(0, 0, 0);
	cout<<result;
}
