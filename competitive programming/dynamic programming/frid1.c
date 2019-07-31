#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007 
long long noofpath[1005][1005];
char path[1005][1005];
int main()
{
	int h,w;
	long long ans;
	cin>>h>>w;
	for(int i=0;i<1005;i++)
	{
		for(int j=0;j<1005;j++)
			noofpath[i][j]=0;
	}
	for(int i=0;i<=h;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(i==0 ||j==0) path[i][j]='#';
			else cin>>path[i][j];
		}
	}
	noofpath[1][1]=1;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(i==1&&j==1) continue;
			if(path[i-1][j]=='.' && path[i][j-1]=='.')
				noofpath[i][j]=(noofpath[i-1][j]+noofpath[i][j-1])%mod;
			else if(path[i][j-1]=='.')
				noofpath[i][j]=(noofpath[i][j-1])%mod;
			else if(path[i-1][j]=='.')
				noofpath[i][j]=(noofpath[i-1][j])%mod;
			//cout<<noofpath[i][j]<<" ";
		}
		//cout<<endl;
	}
	cout<<noofpath[h][w]<<endl;
	return 0;
}