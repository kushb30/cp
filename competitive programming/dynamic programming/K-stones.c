#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int arr[n],dp[k+1]={0};
	for(int i=0;i<n;i++)
		cin>>arr[i];
	dp[0]=0;
	for(int i=1;i<=k;i++)
	{
		int h[3]={0},flag=0;
		vector <int> v;
		for(int j=0;j<n;j++)
		{
			if(i-arr[j]>=0)
			{
				v.push_back(dp[i-arr[j]]);
			}
		}
		if(v.size())
		{
			for(int j=0;j<v.size();j++)
			{
				if(v[j]==0)
				{
	//				cout<<i<<" ";
					flag=1;
					dp[i]=1;
					break;
				}
				h[v[j]]++;
			}
			if(flag==0)
			{
				if(h[2]!=0)
				{
					dp[i]=1;
				}
				else 
					dp[i]=2;	
			}
		}
	//	cout<<dp[i]<<endl;
	}
	if(dp[k]==1)
		cout<<"First"<<endl;
	else cout<<"Second"<<endl;
	return 0;
}