#include<stdio.h>
#include<stdlib.h>
//int SUBSEQMAX(int a[]){
//	int n=;
//	printf("%d   %d\n ",sizeof(a), sizeof(a[0]) );
//	for (int i=0; i<n ; i++ ){
//		printf("%d  ", a[i]);
//	}
//	int smax=a[0];
//	for (int i=1; i<n; i++){
//		smax=(smax+a[i])>a[i]?smax+a[i]:a[i];
//	}
//	return smax;
//}
main(){
	int *a;
	int n;
	scanf("%d", &n);
	a=(int*)malloc(n*sizeof(int));
	for (int i=0; i<n ; i++ ){
		scanf("%d", &a[i]);
	}
	int smax=a[0];
	for (int i=1; i<n; i++){
		smax=(smax+a[i])>a[i]?smax+a[i]:a[i];
	}
	printf("%d", smax);

//  int a[]={1,2,3,1};
//  printf("%d", sizeof(a));
}
