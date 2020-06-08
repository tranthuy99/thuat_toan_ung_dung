#include<iostream>
#include<stdlib.h>
using namespace std;

main(){
	int n; 
	cin>>n;
	int *a=(int *)malloc(n*sizeof(int));
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	
	int doi=0; 
	int tl=0;
	
	for(int i=1; i<n-1; i++){
		if (a[i]>a[i+1]&&a[i]>a[i-1])  {
			int ld=i;
		int rd=i;
		for(int t=i-1; t>=0; t--){
			
			if (a[t]<a[t+1])   ld--;
			else {
			
				break;
			}
		}
	
		for(int t=i+1; t<n; t++){
			if (a[t]<a[t-1]) rd++;
			else {
			
				break;
			}
		}
		int doii=min(i-ld, rd-i);
		doi=max(doi,doii );
		}
		
		if (a[i]<a[i+1]&&a[i]<a[i-1]){
			int ll=i;
		int rl=i;
		for(int t=i-1; t>=0; t--){
			if (a[t]>a[t+1]) ll--;
			else {
			
				break;
			}
		}
		for(int t=i+1; t<n; t++){
			if (a[t]>a[t-1])  rl++;
			else{
			
				break;
			}
		}
		int tli=min(i-ll, rl-i);
		tl=max(tl, tli);
		}
		
	}
	cout<<doi<<" "<<tl;
}
