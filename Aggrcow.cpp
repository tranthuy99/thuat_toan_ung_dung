#include<iostream>
using namespace std;

void quickSort(long long a[], long long l, long long r){
	if (l>=r) return;
    long long m=(l+r)/2;
    long long i=l;
    long long j=r;
    long long pivot=a[m];
    while(i<=j){
    	while(a[i]<pivot) i++;
        while (a[j]>pivot) j--;
        if (i<=j){
    	   long long tmp=a[i];
           a[i]=a[j];
           a[j]=tmp;
           i++;
           j--;
	    }
	}
    if (l<j)    quickSort(a, l, j);
    if (i<r) quickSort(a, i, r);
    
}

bool xepok(long long *a, long long res, long long n, long long c){
	long long count=1;
	long long moc=0;
	for (long long i=1; i<n; i++){
		if (a[i]-a[moc]>=res)  {
			moc=i;
			count++;
		}
		if (count==c)  return true;
	}
	return false;
	
}

int main(){
	long long t;
	cin>>t;
	while(t--){
		long long n, c;
		cin>>n>>c;
		long long*a=new long long[n];
	    for (long long i=0; i<n; i++) cin>>a[i];
	    quickSort(a, 0, n-1);
	    long long min=1;
	    long long max=a[n-1]-a[0];
	    if (c==2)  {
		    cout<<max;
		    return 0;
	    }
	    
	    while (min<max-1){
	    	long long res=(min+max)/2;
	    	cout<<min<<"   "<< max<<"   "<<res<<endl;
	    	if (xepok(a, res, n, c))  min=res;
	    	else max=res;
		}
		cout<<min<<endl;
    }
    return 0;
}
