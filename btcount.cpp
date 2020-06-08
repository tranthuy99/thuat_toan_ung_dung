#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

int ans=0;
char a[]={'(', ')'};

int kiemtra(string a){
	stack<int> l;
		
		int len=a.length();
		int *value=(int*)malloc(len*(sizeof(int)));
		int j=0;
		for (int i=0; i<len; i++){
			if(a[i]=='(')  value[j++]=1;
			if(a[i]==')')  value[j++]=-1;
		}
		
		for(int i=0; i<j; i++){
			if (value[i]>0)  l.push(value[i]);
			if (value[i]<0)  
			   if (!l.empty()){
			   	if ((value[i]+l.top())==0) l.pop();
			   else return 0;
			   } else return 0;
			
			if (i==(j-1)){
				if (l.empty()) return 1;
				else return 0;
			}   
		}
}

void Try(int k, int l, string s){
	if (s[k]=='?') {
		for(int i=0; i<2; i++){
			s[k]=a[i];
			if (k==l-1)  {
				if (kiemtra(s)==1) ans++;
			}else Try(k+1, l, s);
			
		}
		    
	}else {
		if (k==l-1)  {
				if (kiemtra(s)==1) ans++;
			}else Try(k+1, l, s);
	}
}

main(){
	string s;
	cin>>s;
	int l=s.length();
	Try(0, l, s);
	cout<<ans;
}
