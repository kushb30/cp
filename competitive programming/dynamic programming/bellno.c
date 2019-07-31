#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int dp[n][n];
		dp[0][0]=1;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				if(j==0)
					dp[i][j]=dp[i-1][i-1];
				else
					dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
			}
		}
		cout<<dp[n-1][n-1]<<endl;
	}
}