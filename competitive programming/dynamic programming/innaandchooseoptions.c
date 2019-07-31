#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		int count=0;
		bool f1=0,f2=0,f3=0,f4=0,f5=0,f6=0;
		for(int i=0;i<12;i++){
			if(str[i]=='X') {
				f1=1;
				count++;
				break;
			}
		}
		for(int i=0;i<6;i++){
			if(str[i]=='X'){
				if(str[i+6]=='X'){
					f2=1;
					count++;
					break;
				}
			}
		}
		for(int i=0;i<4;i++){
			if(str[i]=='X'&&str[i+4]=='X'&&str[i+8]=='X') {
				f3=1;
				count++;
				break;
			}
		}
		for(int i=0;i<3;i++){
			if(str[i]=='X'&&str[i+3]=='X'&&str[i+6]=='X'&&str[i+9]=='X'){
				f4=1;
				count++;
				break;
			}
		}
		for(int i=0;i<2;i++){
			if(str[i]=='X'&&str[i+2]=='X'&&str[i+4]=='X'&&str[i+6]=='X'&&str[i+8]=='X'&&str[i+10]=='X'){
				f5=1;
				count++;
				break;
			}
		}
		for(int i=0;i<1;i++){
			if(str[i]=='X'&&str[i+1]=='X'&&str[i+2]=='X'&&str[i+3]=='X'&&str[i+4]=='X'&&str[i+5]=='X'&&str[i+6]=='X'&&str[i+7]=='X'&&str[i+8]=='X'&&str[i+9]=='X'&&str[i+10]=='X'&&str[i+11]=='X'){
				f6=1;
				count++;
				break;
			}
		}
		cout<<count<<" ";
		if(f1) cout<<"1x12 ";
		if(f2) cout<<"2x6 ";
		if(f3) cout<<"3x4 ";
		if(f4) cout<<"4x3 ";
		if(f5) cout<<"6x2 ";
		if(f6) cout<<"12x1 ";
		cout<<endl;
	}
	return 0;
}