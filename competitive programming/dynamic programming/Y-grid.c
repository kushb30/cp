#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
	long long fact[200005]={1},ans,mult;
	for(int i=2;i<200005;i++)
		fact[i]=((i%mod)*fact[i-1])%mod;
	int h,w,n;
	cin>>h>>w>>n;
	mult=(fact[h-1]*fact[w-1])%mod;
	ans=fact[h+w-2]/mult;
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		mult=(fact[x-1]*fact[y-1])%mod;
		mult=(mult*((fact[h-x]*fact[w-y]))%mod)%mod;
		ans=ans-((fact[x+y-2]*fact[h+w-x-y])%mod)/mult;
	}
	cout<<ans<<endl;
	return 0;
}