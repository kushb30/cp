#include <bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin>>str;
	int q,arr[100010];
	arr[0]=0;
	for(int i=0;i<str.size()-1;i++){
		if(str[i]==str[i+1]) arr[i+1]=arr[i]+1;
		else arr[i+1]=arr[i];
		//cout<<arr[i]<<endl;
	}
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		if(str[l-1]==str[l]) {
			cout<<arr[r-1]-arr[l]+1<<endl;
		}
		else cout<<arr[r-1]-arr[l]<<endl;
	}
	return 0;
}