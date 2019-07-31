#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long double a[n],v[n+1],prod=1,ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		prod=prod*a[i];
	}
	for(int i=0;i<n+1;i++)
		v[i]=0;
	v[0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j>=0;j--)
		{
			v[j+1]+=v[j]*(1-a[i])/a[i];
		}
	}
	for(int i=0;i<=n/2;i++)
	{
		ans=ans+prod*v[i];
	}
	cout.precision(18);
	cout<<fixed<<ans<<endl;
	return 0;
}