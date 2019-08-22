//18MA20022
//KUSHAGRA BANSAL
//BUCKET SORT

#include <stdio.h>
#include <stdlib.h>

typedef struct bucket
{
	float list[1000000];
	int ind;
}bucket;

//function to print the array
void print(float ans[],int size)
{
	printf("\nThe sorted array is: ");
	for (int i = 0; i < size; ++i)
	{
		/* code */
		printf("%f ",ans[i]);
	}
	printf("\n");
}

//combines the different bucket
void combine(bucket b[],int size, float ans[])
{
	int index=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<b[i].ind;j++)
		{
			ans[index++]=b[i].list[j];
		}
	}
	print(ans,size);
}

//bucket sort
void bucket_sort(float arr[],int size)
{
	int index;
	float ans[size];
	bucket b[size];
	for(int i=0;i<size;i++)
		b[i].ind=0;
	for (int i = 0; i < size; ++i)
	{
		/* code */
		index=size*arr[i];
		b[index].list[b[index].ind]=arr[i];
		b[index].ind++;
	}
	for (int k = 0; k < size; ++k)
	{
		/* code */
		for(int i=1;i<b[k].ind;i++)
		{
			int j=i-1;
			while(j>=0 && b[k].list[j]>b[k].list[j+1])
			{
				float temp=b[k].list[j+1];
				b[k].list[j+1]=b[k].list[j];
				b[k].list[j]=temp;
				j--;
			}
		}
	}
	combine(b,size,ans);
}

int main()
{
	printf("\nEnter the values between 0 to 1 ");
	int size;
	printf("\nEnter the size of the array: ");
	scanf("%d",&size);
	float arr[size];
	printf("\nEnter the elements: ");
	for (int i = 0; i < size; ++i)
	{
		scanf("%f",&arr[i]);
	}
	bucket_sort(arr,size);
	return 0;
}