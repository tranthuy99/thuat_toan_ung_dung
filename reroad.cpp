#include<stdio.h>
#include<stdlib.h>

main(){
	int n;
	int* t, *b;
	int q;
	scanf("%d", &n);
	t=(int *)malloc(n*sizeof(int));
	b=(int *)malloc(n*sizeof(int));
	for (int i=0; i<n; i++)  
	   scanf("%d", &t[i]);
	b[0]=1;
	for (int i=1; i<n; i++)  
	    if (t[i]==t[i-1])   b[i]=0;
	        else b[i]=1;
	int res=0;
	for (int i=0; i<n; i++)
	res=res+b[i];
	scanf("%d", &q);
	while(q--){
		int p;
		scanf("%d", &p);
		scanf("%d", &t[p-1]);
		if (p==1) {
			res=res-b[1];
			if (t[1]!=t[0])  b[1]=1;
			else b[1]=0;
			res+=b[1];
		}
		else if (p==n){
			res=res-b[n-1];
			if (t[n-1]!=t[n-2])  b[n-1]=1;
			else (b[n-1]=0);
			res+=b[n-1];
		}
		else { 
		    res=res-b[p-1]-b[p];
		    if (t[p-1]==t[p-2]) b[p-1]=0;
		    else b[p-1]=1;
		    if (t[p]==t[p-1]) b[p]=0;
		    else b[p]=1;
		    res=res+b[p-1]+b[p];
		}
		printf("%d\n", res);
	}                             
}

