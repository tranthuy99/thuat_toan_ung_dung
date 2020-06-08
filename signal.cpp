#include<stdio.h>
#include<stdlib.h>
 main(){
	int n,b;
	int * a;
	
	scanf("%d%d", &n, &b);
	a=(int *)malloc(n*sizeof(int));
	int res=-1;

	for (int i=0; i<n; i++)  scanf("%d", &a[i]);
	
	int 	*maxLeft=(int *)malloc(n*sizeof(int));
	int     *maxRight=(int *) malloc(n*sizeof(int));
	
	maxLeft[0]=a[0];
	maxRight[n-1]=a[n-1];
	
	for (int i=1; i< n-1; i++)
    	if (maxLeft[i-1]<a[i])  maxLeft[i]=a[i];
    	else maxLeft[i]=maxLeft[i-1];
	
	for (int i=n-2; i>0; i--)
    	if (maxRight[i+1]<a[i])  maxRight[i]=a[i];
	    else maxRight[i]=maxRight[i+1];
	
	for (int i=1; i<n-1; i++){
		if ((maxLeft[i-1]-a[i]>=b )&& (maxRight[i+1]-a[i]>=b))
		    {
			     if (res<(maxLeft[i-1]-a[i]+maxRight[i+1]-a[i]))  res=maxLeft[i-1]-a[i]+maxRight[i+1]-a[i];
		    }
	}
	
	printf("%d", res);
}
