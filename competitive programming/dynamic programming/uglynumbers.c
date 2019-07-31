#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i2=0,i3=0,i5=0;
		cin>>n;
		int a[n];
		a[0]=1;
		for(int i=1;i<n;i++)
		{
			a[i]=min(a[i2]*2,min(a[i3]*3,a[i5]*5));
			if(a[i]==a[i2]*2)
				i2=i2+1;
			if(a[i]==a[i3]*3)
				i3=i3+1;
			if(a[i]==a[i5]*5)
				i5=i5+1;
		//	cout<<a[i]<<endl;
		}
		cout<<a[n-1]<<endl;
	}
	return 0;
}