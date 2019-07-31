#include <bits/stdc++.h>
using namespace std;
int arr[100010],b[100010]={0},c[100010];
int main(){
	int n,ch;
	cin>>n>>ch;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	c[n+1]=0;
	for(int i=n-1;i>=0;i--){
		if(b[arr[i]]==0) {
			c[i+1]=c[i+2]+1;
			b[arr[i]]++;
		}
		else c[i+1]=c[i+2];
	}
	while(ch--){
		int am;
		cin>>am;
		cout<<c[am]<<endl;
	}
	return 0;
}