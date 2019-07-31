#include <bits/stdc++.h>
using namespace std;
int prime[1000000]={1},divisorssum[1000000]={0};
void sieve (){
	for(int i=2;i<1000000;i++){
		for(int j=2*i;j<1000000;j+=i){
				prime[j]=0;
				divisorssum[j]+=i;
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
		if (n!=1) cout<<divisorssum[n]+1<<endl;
		else cout<<divisorssum[n]<<endl;
	}
	return 0;
}