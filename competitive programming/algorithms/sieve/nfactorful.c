#include <bits/stdc++.h>
using namespace std;
int prime[1000010],spf[1000010],dp[1000000][11];
void sieve (){
	for(int i=0;i<1000010;i++) {
		prime[i]=1;
		spf[i]=i;
	}
	for(int i=2;i<1000010;i++){
		if(prime[i]){
			for(int j=2*i;j<1000010;j+=i){
					prime[j]=0;
					if(spf[j]==j) spf[j]=i;
			}
		}
	}
}
int main(){
	int t,stor,arr[10];
	for(int i=0;i<=1000000;i++){
		for(int j=0;j<11;j++){
			dp[i][j]=0;
		}
	}
	cin>>t;
	dp[1][0]=1;
	sieve();
	for(int i=2;i<=1000000;i++){
		for(int j=0;j<10;j++) arr[j]=0;		
		stor=i;
		int c1=0,ind=0;
		while(stor!=1){
			bool flag=0;
			for(int j=0;j<10;j++){
				if(spf[stor]==arr[j]) {
					flag=1;
					break;
				}
			}
			if(flag==0) {
				arr[ind]=spf[stor];
				ind++;
			}
			stor=stor/spf[stor];
		}
		for(int j=0;j<10;j++)
			if(arr[j]!=0) c1++;
		for(int j=0;j<11;j++) {
			if(j==c1) dp[i][j]=dp[i-1][j]+1;
			else dp[i][j]=dp[i-1][j];
		}
	}
//	cout<<spf[7]<<endl;
	while(t--){
		int a,b,p;
		cin>>a>>b>>p;
		cout<<dp[b][p]-dp[a-1][p]<<endl;
	}
	return 0;
}