#include <bits/stdc++.h>
using namespace std;
typedef struct deq
{
	long long a1;
	long long a2;
	long long diff;
	long long inda1;
	long long inda2;
}deq;
int main()
{
	int n,k2,k1;
	cin>>n;
	vector <long long> v;
	long long a,x=0,y=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		v.push_back(a);
	}
	k2=v.size();
	k1=0;
	while(1)
	{
		//cout<<v.size()<<endl;
		if(k2-k1==1)
		{
			x+=v[0];
			break;
		}
		else if(k2-k1==2)
		{
			x+=max(v[k1],v[k1+1]);
			y+=min(v[k1],v[k1+1]);
			//cout<<x<<" "<<y<<endl;
			break;
		}
		else
		{
			deq d[4],min1,max1,ans;
			long long min2=1e12,max2=-1e12;
			d[0].a1=v[k1];
			d[0].a2=v[k1+1];
			d[0].diff=v[k1]-v[k1+1];
			d[0].inda1=k1;
			d[0].inda2=k1+1;
			d[1].a1=v[k1];
			d[1].a2=v[k2-1];
			d[1].diff=v[k1]-v[k2-1];
			d[1].inda1=k1;
			d[1].inda2=k2-1;
			d[2].a1=v[k2-1];
			d[2].a2=v[k1];
			d[2].diff=v[k2-1]-v[k1];
			d[2].inda1=k2-1;
			d[2].inda2=k1;
			d[3].a1=v[k2-1];
			d[3].a2=v[k2-1-1];
			d[3].diff=v[k2-1]-v[k2-2];
			d[3].inda1=k2-1;
			d[3].inda2=k2-2;
			for(int i=0;i<4;i++)
			{
				if(d[i].diff<min2)
				{
					min2=d[i].diff;
					min1=d[i];
				}
			}
			for(int i=0;i<4;i++)
			{
				if(d[i].inda1==min1.inda1)
					continue;
				else
				{
					if(d[i].diff>max2)
					{
						max2=d[i].diff;
						max1=d[i];
					}
				}
			}
			//cout<<max2<<endl;
			for(int i=0;i<4;i++)
			{
				if(d[i].inda1==min1.inda1)
				{
					continue;
				}
				else if(d[i].inda2==max1.inda2 && d[i].inda1==max1.inda1)
					continue;
				else
					ans=d[i];
			}
			x+=ans.a1;
			y+=ans.a2;
			int c1=k1,c2=k2;
			//cout<<x<<endl;
			if(ans.inda1==k1)
				k1=k1+1;
			else 
				k2=k2-1;
			if(ans.inda2==c1)
				k1=k1+1;
			else if(ans.inda2==c1+1)
				k1=k1+1;
			else if(ans.inda2==c2)
				k2=k2-1;
			else
				k2=k2-1;
			//cout<<k2<<endl;
		}
	}
	cout<<x-y<<endl;
	return 0;
}