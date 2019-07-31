#include <bits/stdc++.h>
using namespace std;
int arr[1000010],b[1000010]={0},c[1000010];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		b[arr[i]]++;
	}
	c[0]=0;
	for(int i=0;i<1000001;i++){
		c[i]=b[i]+c[i-1];
	}
	int ch;
	cin>>ch;
	while(ch--){
		int am;
		cin>>am;
		if( am<=1000000)cout<<c[am]<<endl;
		else cout<<n<<endl;
	}
	return 0;
}