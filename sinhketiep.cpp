#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
	int n;
	int t1=-1;
	int *a;
	cin>>n;
	a=(int*)malloc(n*sizeof(int));
	for (int i=0; i<n; i++)
	cin>>a[i];
	for(int i=n-1; i>=0; i--){
		if (a[i]>a[i-1])  {
			t1=i-1;
			break;
		}
	}
	if (t1==-1) {
		cout<<-1;
		return 0;
	}
	for (int i=n-1; i>t1; i--)
	if (a[i]>a[t1]) {
		int tmp=a[i];
		a[i]=a[t1];
		a[t1]=tmp;
		break;
	}
	for(int i=0; i<=t1; i++) cout<<a[i]<<" ";
	for (int i=n-1; i>t1; i--) cout<<a[i]<<" ";
	return 0;
}
