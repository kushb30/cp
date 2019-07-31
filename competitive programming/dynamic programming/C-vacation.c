#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int happ[n][3],dp[n][3];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
			cin>>happ[i][j];
	}
	dp[0][0]=happ[0][0];
	dp[0][1]=happ[0][1];
	dp[0][2]=happ[0][2];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(j==0) dp[i][j]=happ[i][j]+max(dp[i-1][j+1],dp[i-1][j+2]);
			else if(j==1) dp[i][j]=happ[i][j]+max(dp[i-1][j+1],dp[i-1][j-1]);
			else dp[i][j]=happ[i][j]+max(dp[i-1][j-1],dp[i-1][j-2]);
		}
	}
	cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl;
	return 0;
}