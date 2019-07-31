#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,sum;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cin>>sum;
		int dp[sum+1]={0};
		dp[0]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<=sum;j++)
			{
				if(j-arr[i]==0)
					dp[j]=dp[j]+1;
				else if(j-arr[i]>0)
					dp[j]=dp[j]+dp[j-arr[i]];
			}
		}
		cout<<dp[sum]<<endl;
	}
}