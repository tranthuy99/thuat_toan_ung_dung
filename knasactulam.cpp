#include<iostream>
using namespace std;
int n, b;
int f=0;
int result=0;
int mask=0;
void xet(int k, int a[], int c[]){
	for (int i=0; i<n; i++){
		if (~(mask>>i&1)){
		if (a[i]<=b) {
			b=b-a[i];
			f=f+c[i];
			
			xet(k+1, a, c);
		}
		else if (f>result)  result = f;
		f=f-c[i];
        b=b+a[i];
        mask=mask-(1<<i);
	}
}
	
}

main(){
	
	cin>>n>>b;
	int *a=new int[n];
	int *c=new int[n];
	for (int i=0; i<n; i++)  cin>>a[i]>>c[i];
	//cout<<"aaaaa";
	xet(0, a, c);
	cout<<result;
}
