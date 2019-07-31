#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	int cost,min1=1000000,min3=1000000,min2=1000000,a,b,c,ind=0;
	cin>>t;
	string s1,s2,s3;
	int size1,size2,size3;
	while(t--){
		
		string str;
		cin>>cost>>str;
		for(int i=0;i<str.size();i++){
			if(str[i]=='A') {
				if(min1>cost){
					min1=cost;
					a=ind;
					s1=str;
					size1=str.size();
				}
			}
			if(str[i]=='B') {
				if(min2>cost){
					min2=cost;
					b=ind;
					s2=str;
					size2=str.size();
				}
			}
			if(str[i]=='C') {
				if(min3>cost){
					min3=cost;
					c=ind;
					s3=str;
					size3=str.size();
				}
			}
		}
		ind++;
	}
	if(min1==1000000||min2==1000000||min3==1000000) cout<<"-1";
	else {
		if(a==b&&a==c) cout<<min1<<endl;
		else if(a==b) cout<<min1+min3<<endl;
		else if(b==c) cout<<min1+min2<<endl;
		else if(a==c) cout<<min1+min2<<endl;
		else {
			if(size1==2){
				for(int i=0;i<s1.size();i++){
					if(s1[i]=='B') min2=0;
					else min3=0;
				}
			}
			if(size2==2){
				for(int i=0;i<s2.size();i++){
					if(s2[i]=='A') min1=0;
					else min3=0;
				}
			}
			if(size3==2){
				for(int i=0;i<s3.size();i++){
					if(s3[i]=='A') min1=0;
					else min2=0;
				}
			}
			if(size1==3) {
				min2=0;
				min3=0;
			}
			if(size2==3) {
				min1=0;
				min3=0;
			}
			if(size3==3) {
				min2=0;
				min1=0;
			}
			cout<<min1+min2+min3<<endl;
		}
	}
	return 0;
}