#include<iostream>
#include<stdlib.h>

using namespace std;

void nhap(long long x[],long long m[], long long n){
	for (long long i=0; i<n ;i++ ){
		cin>>x[i]>>m[i];
	}
}

void quickSort(long long arr[],long long m[], long long left, long long right){
	if (left >= right)
      return;

    long long middle = left + (right - left) / 2;
    long long pivot = arr[middle];
    long long i = left, j = right;

    while (i <= j) {
      while (arr[i] < pivot) {
        i++;
      }

      while (arr[j] > pivot) {
        j--;
      }

      if (i <= j) {
        long long temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        temp=m[i];
        m[i]=m[j];
        m[j]=temp;
        i++;
        j--;
      }
    }

    if (left < j)
      quickSort(arr,m, left, j);

    if (right > i)
      quickSort(arr,m, i, right);
}

void giaoHang(long long x[],long long m[],long long n, long long k){
	long long t=0;
	long long thua=0;
	long long tg;
	for (long long i=0; i<n; i++){
		if (x[i]<0){
			if (thua>=m[i]) {
				thua=thua-m[i];
			
			}
			else {
				m[i]=m[i]-thua;
				if (m[i]%k==0){
					tg=m[i]/k;
					t=t-2*tg*x[i];
					thua=0;
				}else {
					tg=m[i]/k+1;
					t=t-2*tg*x[i];
					thua=k-m[i]%k;				}
			}
		}else break;
		
		
	}
	thua=0;
	for(long long i=n-1; i>=0; i--){
		if (x[i]>0){
			if (thua>=m[i]) {
				thua=thua-m[i];
				
			}
			else {
				m[i]=m[i]-thua;
				if (m[i]%k==0){
					tg=m[i]/k;
					t=t+2*tg*x[i];
					thua=0;
				}else {
					tg=m[i]/k+1;
					t=t+2*tg*x[i];
					thua=k-m[i]%k;				}
			}
		}else break;
	}
	cout<< t;
}

main(){
	long long n, k;
	long long x[10000];
	long long m[10000];
	long long vt;
	cin>>n>>k;
	if (n==0) {
		cout<<0;
		return 0;
	}
	nhap(x, m, n);
	
	quickSort(x,m, 0, n-1);
	
	
	giaoHang(x, m, n, k);
	
}
