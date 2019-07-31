#include <bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin>>str;
	int c1=0,c2=0,ans=0;
	for(int i=0;i<str.size();i++){
		if(str[i]=='Q') c1++;
		if(str[i]=='A'&&c1!=0){
			for(int j=i+1;j<str.size();j++) 
				if(str[j]=='Q') c2++;
		ans+=c1*c2;	
		c2=0;
		} 
	}
	cout<<ans<<endl;
	return 0;
}