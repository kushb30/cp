//Name-Kushagra Bansal
//Roll no 18MA20022
//implementation of merge sort and insertion sort and comparing their runtime via comparing thier comparisons

#include<stdio.h>
int count=0;
//inertion sort
void insertion_sort(int array[],int n)
{
	int comp=0;
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		while(j>=0 && array[j]>array[j+1])
		{
			comp++; //count the number of comparisions in insertion sort
			int temp=array[j+1];
			array[j+1]=array[j];
			array[j]=temp;
			j--;
		}
	}

	printf("Printing the sorted array after insertion sort:   ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	printf("Number of comparisons in inserted sort is: %d\n",comp);
}
//function to merge the two sorted arrays
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
		count++; //count the number of comparisons in merge sort
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
//recursive call for merge sort
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
	printf("Enter the number of elements to be sorted: ");
	int n;
	scanf("%d",&n);
	int array[n],arr[n];
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",array+i);
		arr[i]=array[i];
	}
	printf("Printing the unsorted array: ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	insertion_sort(array, n);
	mergesort(arr,0,n-1);
	printf("Printing the sorted array after merge sort:   ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("Number of comparisons in merge sort is: %d\n",count);
	return 0;
}
