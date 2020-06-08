#include<iostream>
using namespace std;
int n, m;
int count=0;
void tim(int k, int du, int *a){
	if (k==n-1) {
		if (du%a[n-1]==0)  count++;
	}
	else{	
	int t=du/a[k];
	for(int i=1; i<=t; i++){
		int dunew=du-a[k]*i;
			if (dunew>=a[k+1]) tim(k+1, dunew, a);
			else continue;
		}
	}
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int*a=new int[n];
	for(int i=0; i<n; i++)  cin>>a[i];
	int du=m;
	
	tim(0, du, a);
	cout<<count;
}
