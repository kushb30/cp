#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		if(k>n)
		{
		    cout<<0<<endl;
		    continue;
		}
		long long int dp[n+1][k+1];
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(i,k);j++)
			{
				if(j==0 || j==i)
					dp[i][j]=1;
				else
					dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%1000000007;
			}
		}
		cout<<dp[n][k]<<endl;
	}
}