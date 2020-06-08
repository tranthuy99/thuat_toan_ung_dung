#include<iostream>
#include<stdlib.h>
#include<stack>

using namespace std;

int main(){
	string a;
	int t;
	cin>>t;
	
	
	while(t--){
		stack<int> l;
		//cout<<l.top()<<"toppp";
		cin>>a;
		//int flag;
		int len=a.length();
		int *value=(int*)malloc(len*(sizeof(int)));
		int j=0;
		for (int i=0; i<len; i++){
			if(a[i]=='(')  value[j++]=1;
			if(a[i]==')')  value[j++]=-1;
			if(a[i]=='[')  value[j++]=2;
			if(a[i]==']')  value[j++]=-2;
			if(a[i]=='{')  value[j++]=3;
			if(a[i]=='}')  value[j++]=-3;
		}
		//cout<<j<<"jjjj";
		//for (int i=0; i<j; i++) cout<<value[i];
		for(int i=0; i<j; i++){
			if (value[i]>0)  l.push(value[i]);
			if (value[i]<0)  
			   if (!l.empty()){
			   	if ((value[i]+l.top())==0) l.pop();
			   else {
			   	//flag=0;
			   	cout<<0<<endl;
			   	break;
			   }
			   } else {
			   	cout<<0<<endl;
			   	break;
			   }
			   //cout<<l.top()<<endl;
			if (i==(j-1)){
				if (l.empty()) cout<<1<<endl;
				else cout<<0<<endl;
			}   
		}
	
		
		
	}
}
