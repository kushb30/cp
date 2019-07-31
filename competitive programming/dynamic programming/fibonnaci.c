#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	long long int fib[1005];
	fib[0]=1;
	fib[1]=1;
	for(int i=2;i<1005;i++)
		fib[i]=(fib[i-1]+fib[i-2])%1000000007;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<fib[n-1]<<endl;
	}
}