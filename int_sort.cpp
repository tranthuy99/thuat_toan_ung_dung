#include<iostream>
#include<stdlib.h>
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
	int n;
	cin>>n;
	int* a=(int *)malloc(n*sizeof(int));
	for (int i=0; i<n; i++)
	cin>>a[i];
	quickSort(a, 0, n-1);
	for (int i=0; i<n; i++)
	cout<<a[i]<<" ";
}
