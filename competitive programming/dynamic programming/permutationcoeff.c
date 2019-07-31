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
		long long prod,ans=1;
		prod=n-k+1;
		for(int i=0;i<k;i++)
		{
			ans=ans*prod;
			prod=prod+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}