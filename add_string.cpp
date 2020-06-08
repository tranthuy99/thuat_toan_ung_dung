#include <iostream>
using namespace std;

string sum(string a, string b){
	string kq;
	while (a.length()<b.length())  a='0'+a;
	while (b.length()<a.length())  b='0'+b;
	int nho=0;
	int tong;
	for (int i=b.length()-1; i>=0 ; i--){
		tong=a[i]-'0'+b[i]-'0'+nho;
		kq=(char)(tong%10+'0')+kq;
		nho=tong/10;
	}
	if (nho==1)  kq='1'+kq;
	return kq;
}

int main(){
	string a,b;
	cin>>a>>b;
	cout<<sum(a,b);
	return 0;
}
