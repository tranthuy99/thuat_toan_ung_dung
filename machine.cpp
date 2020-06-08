#include<iostream>

using namespace std;

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N=2000001;
	int n;
	cin>>n;
	int*s=new int[n];
	int*t=new int[n];
	for(int i=0; i<n; i++) cin>>s[i]>>t[i];
	int *maxs=new int [N];
	
	for (int i=0; i<n; i++){
		maxs[t[i]]= max(maxs[t[i]], t[i]-s[i]);
	}
	for (int i=1; i<N; i++) 
	maxs[i]=max(maxs[i-1], maxs[i]);
	
	int res=-1;

	for (int i=0; i<n; i++)
	   {
	   	if (maxs[s[i]-1]>0)   
	       res=max(res, maxs[s[i]-1]+t[i]-s[i]);
	   }
	cout<<res;
}
