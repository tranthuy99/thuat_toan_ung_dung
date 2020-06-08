#include<stdio.h>

void ADD(unsigned long long a, unsigned long long b){
	unsigned long long a1=a/10;
	unsigned long long a0=a%10;
	unsigned long long b1=b/10;
	unsigned long long b0=b%10;
	unsigned long long c1=(b0+a0)/10;
	unsigned long long c0=(b0+a0)%10;
	if (a1+b1+c1!=0) printf("%d", a1+b1+c1);
	printf("%d", c0);
	
}
main(){
	unsigned long long a, b;
	scanf("%d%d", &a, &b);
	ADD(a,b);
}
