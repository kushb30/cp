#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int w;
		cin>>w;
		int dp[w+1];
		dp[0]=1;
		dp[1]=1;
		for(int i=2;i<=w;i++)
			dp[i]=dp[i-1]+dp[i-2];
		cout<<dp[w]<<endl;
	}
	return 0;
}