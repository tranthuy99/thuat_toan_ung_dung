#include<stdio.h>
#include<stdlib.h>

main(){
	int n;
	scanf("%d", &n);
	int *a=(int *)malloc(n*sizeof(int));
	for (int i=0; i<n; i++)
	scanf("%d", &a[i]);
	int j=0;
	while (j!=n-1){
		if (a[j+1]>=a[j])  j++;
		else {
			for (int i=j; i>=0; i--)
		         if (a[i+1]<a[i]) {
				 int tg=a[i];
				 a[i]=a[i+1];
				 a[i+1]=tg;
				 }
				 j++;
		}
	}
	for (int i=0; i<n; i++)
	printf("%d\t",a[i]);
}
