#include<iostream>
using namespace std;
 main(){
 	int n, k;
 	cin>>n>>k;
 	int *a=new int [n];
 	for(int i=0; i<n; i++){
 		cin>>a[i];
	 }
	 int count=0;
	 for(int i=0; i<n-3; i++){
	 	if (a[i]<k) {
	 		int du=k-a[i];
	 		for (int j=i+1; j<n-2;j++ ){
	 		     if (a[j]<du) {
	 		     	for (int k=j+1; k<n; k++) 
	 		     	     if (a[k]==(du-a[j])) count++;
				  }
		    }
		 }
	 	
	 }
	 cout<<count;
 }
