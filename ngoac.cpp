#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<list>

using namespace std;

main(){
	string a;
	list<char> l;
	int t;
	cin>>t;
	while(t--){
		fflush(stdin);
		getline(cin, a);
		int len=a.length();
		int flag=0;
		for(int i=0; i<len; i++){
			if (a[i]==' ') continue;
			if (a[i]==')') {
				if (l.back()=='(') l.pop_back();
				else {
					flag=0;
					break;
				}
			}
			else if (a[i]==']') {
				if (l.back()=='[') l.pop_back();
				else {
					flag=0;
					break;
				}
			}
			else if (a[i]=='}') {
				if (l.back()=='{') l.pop_back();
				else {
					flag=0;
					break;
				}
			}
			else l.push_back(a[i]);
			
		}
		
		if (l.empty()) flag=1;
		
		cout<<flag<<endl;
	}
}
