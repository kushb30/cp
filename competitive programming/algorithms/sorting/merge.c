#include <bits/stdc++.h>
using namespace std;
void merge(int arr[],int beg,int mid,int end)
{
	int left_arr[mid-beg+1],right_arr[end-mid];
	for(int i=0; i<mid-beg+1; i++)
	{
		left_arr[i]=arr[beg+i];
	}
	for(int i=0; i<end-mid; i++)
		right_arr[i]=arr[mid+1+i];
	int i=0,j=0,k=beg;
	//cout<<mid<<endl;
	while(1)
	{
		if(i==mid-beg+1 || j==end-mid) break;
		if(left_arr[i]>right_arr[j])
		{
			arr[k]=right_arr[j];
			j++;
		}
		else 
		{
			arr[k]=left_arr[i];
			i++;
		}
		k++;
	}
	if(i!=mid-beg+1)
	{
		for(int l=i;l<mid-beg+1;l++)
		{
			arr[k]=left_arr[l];
			k++;
		}
	}
	else 
	{
		for(int l=j;l<end-mid;l++)
		{
			arr[k]=right_arr[l];
			k++;
		}	
	}
}
void mergesort(int arr[],int beg,int end)
{
	if(end>beg)
	{
		int mid=(end+beg)/2;
		mergesort(arr,beg,mid);
		mergesort(arr,mid+1,end);
		merge(arr,beg,mid,end);
	}
}
int main()
{
	int n,end,beg=0;
	cin>>n;
	end=n-1;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	mergesort(arr,beg,end);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}