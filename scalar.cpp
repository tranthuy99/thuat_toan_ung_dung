#include<iostream>
using namespace std;

void quickSort(int a[], int l, int r){
	if (l>=r) return;
    int m=(l+r)/2;
    int i=l;
    int j=r;
    int pivot=a[m];
    while(i<=j){
    	while(a[i]<pivot) i++;
        while (a[j]>pivot) j--;
        if (i<=j){
    	   int tmp=a[i];
           a[i]=a[j];
           a[j]=tmp;
           i++;
           j--;
	    }
	}
    if (l<j)    quickSort(a, l, j);
    if (i<r) quickSort(a, i, r);
    
}


main(){
	int t, n;
	int x[1005];
	int y[1005];
	
	cin>>t; 
	for (int j=1; j<=t; j++){
		int ans=0;
		cin>>n;
		for (int i=0; i<n; i++){
			cin>>x[i];			
		}
		for (int i=0; i<n; i++){
			cin>>y[i];			
		}
		quickSort(x, 0, n-1);
		quickSort(y, 0, n-1);
		for (int i=0; i<n; i++){
			ans=ans+x[i]*y[n-i-1];			
		}
		cout<<"Case #"<<j<<": "<<ans<<endl;
	}
}
