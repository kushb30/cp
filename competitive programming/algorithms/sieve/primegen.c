#include <bits/stdc++.h>
using namespace std;
int prime[1010];
void sieve (){
	for(int i=0;i<1010;i++) prime[i]=1;
	for(int i=2;i<1010;i++){
	//	cout<<prime[i]<<endl;
		if(prime[i]){
			for(int j=2*i;j<1010;j+=i){
					prime[j]=0;
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	sieve();
	while(t--){
		int n;
		cin>>n;
		//cout<<prime[2];
		for(int i=1;i<=1000;i++){
			if(i>n) break;
			else {
				if(prime[i]) cout<<i<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}