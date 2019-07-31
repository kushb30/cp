#include <bits/stdc++.h>
using namespace std;
typedef struct points
{
	int x,y;
}points;

void mergex(int i1, int e1, int i2, int e2, points arr[])
{
	points to_copy[e2-i1+1];
	int k1,k2;
	k1 = i1;
	k2 = i2;
	int l=0;
	while(k1<=e1 && k2<=e2)
	{
		if(arr[k1].x <= arr[k2].x)
		{
			to_copy[l].x = arr[k1].x;
			to_copy[l].y=arr[k1].y;
			k1++;
			l++;
		}
		else 
		{
			to_copy[l].x = arr[k2].x;
			to_copy[l].y=arr[k2].y;
			k2++;
			l++;
		}
	}
	if(k1 > e1)
	{
		while(k2<=e2)
		{
			to_copy[l].x = arr[k2].x;
			to_copy[l].y=arr[k2].y;
			l++;
			k2++;
		}
	}
	else if(k2 > e2)
	{
		while(k1<=e1)
		{
			to_copy[l].x = arr[k1].x;
			to_copy[l].y=arr[k1].y;
			k1++;
			l++;
		}
	}
	l=0;
	for(int j=i1; j<=e2; j++)
	{
		arr[j].x = to_copy[l].x;
		arr[j].y=to_copy[l].y;
		l++;
	}
}

void mergey(int i1, int e1, int i2, int e2, points b[])
{
	points to_copy[e2-i1+1];
	int k1,k2;
	k1 = i1;
	k2 = i2;
	int l=0;
	while(k1<=e1 && k2<=e2)
	{
		if(b[k1].y <= b[k2].y)
		{
			to_copy[l].x = b[k1].x;
			to_copy[l].y=b[k1].y;
			k1++;
			l++;
		}
		else 
		{
			to_copy[l].x = b[k2].x;
			to_copy[l].y=b[k2].y;
			k2++;
			l++;
		}
	}
	if(k1 > e1)
	{
		while(k2<=e2)
		{
			to_copy[l].x = b[k2].x;
			to_copy[l].y=b[k2].y;
			l++;
			k2++;
		}
	}
	else if(k2 > e2)
	{
		while(k1<=e1)
		{
			to_copy[l].x = b[k1].x;
			to_copy[l].y=b[k1].y;
			k1++;
			l++;
		}
	}
	l=0;
	for(int j=i1; j<=e2; j++)
	{
		b[j].x = to_copy[l].x;
		b[j].y=to_copy[l].y;
		l++;
	}
}


void merge_sortx(int i, int e, int len, points arr[])
{
	int mid;
	mid = (i+e)/2;
	if(len == 1)
		return;
	merge_sortx(i,mid,mid-i+1,arr);
	merge_sortx(mid+1,e,e-mid,arr);
	mergex(i,mid,mid+1,e,arr);
}

void merge_sorty(int i, int e, int len, points b[])
{
	int mid;
	mid = (i+e)/2;
	if(len == 1)
		return;
	merge_sorty(i,mid,mid-i+1,b);
	merge_sorty(mid+1,e,e-mid,b);
	mergey(i,mid,mid+1,e,b);
}



float dis1(int x1,int x2,int y1,int y2)
{
	return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

float  findmin(points arr[],points b[],int beg,int end,int n)
{
	points strip[n];
	int mid=(beg+end)/2,l=0;
	float min_dis,strip_dis=9999999,d1,d2;
	if(end-beg+1==2)
	{
		//cout<<arr[beg].x<<" "<<arr[beg].y<<" "<<arr[end].x<<" "<<arr[end].y<<endl;
		min_dis= dis1(arr[beg].x,arr[end].x,arr[beg].y,arr[end].y);
		//cout<<min_dis<<endl;
		return min_dis;
	}
	if(end-beg+1==1)
	{
		return 10000000;
	}
	d1=findmin(arr,b,beg,mid,n);
	//cout<<d1<<endl;
	d2=findmin(arr,b,mid+1,end,n);
	min_dis=min(d1,d2);
	for(int i=0;i<n;i++)
	{
		if(abs(b[i].x-arr[mid].x)<=min_dis)
		{
			strip[l].x=b[i].x;
			strip[l].y=b[i].y;
			l++;
		}
	}
	for(int i=0;i<l;i++)
	{
		int count=0,j=i+1;
		while(1)
		{	
			if(count==7) break;
			if(j==l) break;
			strip_dis=min(strip_dis,dis1(strip[i].x,strip[j].x,strip[i].y,strip[j].y));
			min_dis=min(min_dis,strip_dis);
			count++;
			j++;
		}
	}
	return min_dis;
}

int main()
{
	int n;
	float min_dis;
	cin>>n;
	points arr[n],b[n];
	for(int i=0;i<n;i++)
		cin>>arr[i].x>>arr[i].y;
	for(int i=0;i<n;i++)
	{
		b[i].x=arr[i].x;
		b[i].y=arr[i].y;
	}
	merge_sortx(0,n-1,n,arr);
	merge_sorty(0,n-1,n,b);
//	 for(int i=0;i<n;i++)
//		 cout<<b[i].x<<" "<<b[i].y<<endl;
	min_dis=findmin(arr,b,0,n-1,n);
	cout<<min_dis<<endl;
	return 0;
}