#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,arr[3],x,y,stor,a,b;
	cin>>n;
	int dp[n+1][3],maxcoin[n+1];
	for(int i=0;i<3;i++) {
		dp[0][i]=1;
		cin>>arr[i];
	}
	sort(arr,arr+3);
	for(int i=1;i<n+1;i++) maxcoin[i]=-1;
	maxcoin[0]=0;
	for(int i=1;i<n+1;i++){
		for(int j=0;j<3;j++){
			if(i-arr[j]>=0) x=dp[i-arr[j]][j];
			else x=0;
			if(j>=1) y=dp[i][j-1];
			else y=0;
			dp[i][j]=x+y;
			if(dp[i][j]!=0&&i-arr[j]>=0) {
				stor=1+maxcoin[i-arr[j]];
				a=maxcoin[i];
				b=max(a,stor);
				maxcoin[i]=b;
			}
		}
	}
	cout<<maxcoin[n]<<endl;
	return 0;
}