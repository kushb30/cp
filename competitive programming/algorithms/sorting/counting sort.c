//18MA20022
//KUSHAGRA BANSAL
//COUNTING SORT

#include <stdio.h>
#include <stdlib.h>

//function to print the array
void print(int ans[],int size)
{
	printf("\nThe sorted array is: ");
	for (int i = 1; i <= size; ++i)
	{
		/* code */
		printf("%d ",ans[i]);
	}
}

//counting sort 
void counting_sort(int arr[],int size,int hash[])
{
	int max_element=-1,ans[size+1];
	for (int i = 0; i < size; ++i)
	{
		hash[arr[i]]++;
		if(arr[i]>max_element)
			max_element=arr[i];
	}
	int dp[max_element+1];
	for (int i = 0; i <= max_element; ++i)
	{
		/* code */
		dp[i]=0;
	}
	dp[0]=hash[0];
	for (int i = 1; i <= max_element; ++i)
	{
		/* code */
		dp[i]=dp[i-1]+hash[i];
	}
	for (int i = 0; i <size; ++i)
	{
		/* code */
		if(dp[arr[i]])
		{
			ans[dp[arr[i]]]=arr[i];
			dp[arr[i]]--;
		}
	//	printf("\n%d",arr[i]);
	}
	print(ans,size);

}

int main()
{
	printf("\nThe elements should be positive and less than 1000000");
	int size;
	printf("\nEnter the size of the array: ");
	scanf("%d",&size);
	int arr[size],hash[1000000]={0};
	printf("\nEnter the elements: ");
	for (int i = 0; i < size; ++i)
	{
		scanf("%d",&arr[i]);
	}
	counting_sort(arr,size,hash);
	return 0;
}