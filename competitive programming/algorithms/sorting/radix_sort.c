//18MA20022
//KUSHAGRA BANSAL
//RADIX SORT


#include <stdio.h>
#include <stdlib.h>

int maximum(int arr[],int size)
{
	int max=-1;
	for (int i = 0; i < size; ++i)
	{
		/* code */
		if(max<arr[i])
			max=arr[i];
	}
	return max;
}

void print(int ans[],int size)
{
	printf("\nThe sorted array is: ");
	for (int i = 0; i < size; ++i)
	{
		/* code */
		printf("%d ",ans[i]);
	}
	printf("\n");
}

void count_sort(int arr[],int size,int exp)
{
	int ans[size+1],count[10]={0};
	for(int i=0;i<size;i++)
		count[(arr[i]/exp)%10]++;
	for(int i=1;i<10;i++)
		count[i]+=count[i-1];
	for (int i = size-1; i >=0; i--)
	{
		/* code */
		if(count[(arr[i]/exp)%10])
		{
			ans[count[(arr[i]/exp)%10]]=arr[i];
			count[(arr[i]/exp)%10]--;
		}
	}
	for(int i=0;i<size;i++)
		arr[i]=ans[i+1];
}

void radix_sort(int arr[],int size)
{
	int max=maximum(arr,size);
	for(int i=1;max/i>0;i=i*10)
		count_sort(arr,size,i);
}



int main()
{
	int size;
	printf("\nEnter the size of the array: ");
	scanf("%d",&size);
	int arr[size];
	printf("\nEnter the elements: ");
	for (int i = 0; i < size; ++i)
	{
		scanf("%d",&arr[i]);
	}
	radix_sort(arr,size);
	print(arr,size);
	return 0;
}