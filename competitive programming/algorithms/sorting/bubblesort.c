#include <bits/stdc++.h>
using namespace std;
void swap(int arr[],int i,int k)
{
	int temp;
	temp=arr[i];
	arr[i]=arr[k];
	arr[k]=temp;
}
int *bubblesort(int num,int arr[])
{
	int k=0;
	while(true)
	{
		int flag=0;
		for(int i=k+1;i<num;i++)
		{
			if(arr[k]>arr[i])
			{
				flag=1;
				swap(arr,i,k);
				k=i;
			}
		}
		if(flag==0) k++;
		else k=0;
		if(k==num) break;
	}
	return arr;
}
int main()
{
	int num,*ptr;
	cin>>num;
	int arr[num];
	for(int i=0;i<num;i++)
		cin>>arr[i];
	ptr=bubblesort(num,arr);
	for(int i=0;i<num;i++)
		cout<<*(ptr+i)<<" ";
	return 0;
}