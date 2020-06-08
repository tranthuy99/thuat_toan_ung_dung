#include<iostream>
using namespace std;

void quickSort(long long a[], long long l, long long r){
	if (l>=r) return;
    long long m=(l+r)/2;
    long long i=l;
    long long j=r;
    long long pivot=a[m];
    while(i<=j){
    	while(a[i]<pivot) i++;
        while (a[j]>pivot) j--;
        if (i<=j){
    	   long long tmp=a[i];
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
	long long n, l;
	cin>>n>>l;
	long long *a=new long long[n];
	for(long long i=0; i<n; i++)  cin>>a[i];
	quickSort(a, 0, n-1);
	double d=a[0];
	for(long long i=1; i<n; i++) d=max(d, (a[i]-a[i-1])/2.0);
	d=max(d, 1.0*l-a[n-1]);
	printf("%.10f", d);
	
}
