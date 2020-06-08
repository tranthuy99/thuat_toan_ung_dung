#include<stdio.h> //phep cong voi so lon
#include<string.h>

void cong2SoDuong(char a[], char b[]){
	int la=strlen(a);
	int lb=strlen(b);
	char nho=0;
	char c[la+1];
	char t;
	for(int i=la-1; i>=la-lb; i--){
		t=a[i]-'0'+b[i-la+lb]-'0'+nho;
		c[la-i-1]=t%10+'0';
		nho =t/10;
	}
	for(int i=la-lb-1; i>=0; i--){
		t=a[i]-'0'+nho;
		c[la-i-1]=t%10+'0';
		nho =t/10;
	}
	if (nho!=0) {
		c[la]=nho+'0';
		c[la+1]='\0';
		strrev(c);
		printf("%s", c);
	}else 	{
		
		c[la]='\0';
		strrev(c);
		printf("%s", c);
	}
}


main(){
	char a[100];
	char b[100];
	scanf(" %s", a);
	scanf(" %s", b);
	if (strlen(a)<strlen(b)){
		cong2SoDuong(b,a);
	}else
	cong2SoDuong(a,b);
}
