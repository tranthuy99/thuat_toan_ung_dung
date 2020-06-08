#include<iostream>
using namespace std;

main(){
	int a, b, c;
	int ucln;
	cin>>a>>b>>c;
	int ans=0;
	if (a<b) {
		int tmp=a;
		a=b; b=tmp;
	}
	for(int i=a; i>0; i--){
		if ((a%i==0)&(b%i==0)) {
			ucln=i;
			break;
		}
	}
	//cout<<"----\n";
	if (c%ucln!=0) {
		cout<<1;
		return 0;
	}
		//cout<<"----\n";
	int x=0;
	int y=0;	
	while((x!=c)&&(y!=c)){
		if (x==a) {
			x=0;
			ans++;
		}
		if (y==0) {
			y=b;
			ans++;
		}	
		if (y>0){
			if (a-x<=y) {
				y=y+x-a;
				x=a;ans++;
			}
			else {
				x=x+y;
				y=0;ans++;
			}
		}
	}
	cout<<ans;
}
