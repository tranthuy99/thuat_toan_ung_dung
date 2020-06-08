#include<iostream>
using namespace std;

int n, k;


void tinhgt(int *gt){
	gt[1]=1;int t=1;
	for (int i=2; i<=13; i++){
		gt[i]=i*gt[i-1];
	}
//	return t;
}

void permutationlist(int t, int *a, int *gt){
	if (k==1) return;
	int buoc=(k-1)/gt[t-1];
	int tmp=a[n-t+1+buoc];
	for (int i=n-t+1+buoc; i>n-t+1; i--) a[i]=a[i-1];
	a[n-t+1]=tmp;
	k=k-buoc*gt[t-1];
	for (int i=1; i<13; i++) if (gt[i]>=k) {
		t=i;
		break;
	}
	return permutationlist(t, a, gt);
}

int main(){
	cin>>n>>k;
	
	int *gt=new int[14];
	int *a=new int[n+1];
	for(int i=1; i<n+1; i++) a[i]=i;
	
	tinhgt(gt);
	if (n<13 && k>gt[n]) {
		cout<<-1;
		return 0;
	}
	int t;
	for (int i=1; i<13; i++) if (gt[i]>=k) {
		t=i;
		break;
	}
	//cout<<t;
	permutationlist(t, a, gt);//cout<<"aaaa";
	for(int i=1; i<n+1; i++) cout<<a[i]<<" ";
}
