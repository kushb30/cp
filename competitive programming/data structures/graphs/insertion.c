
#include <stdio.h>  
int insertionSortRecursive(int arr[], int n,int comp) 
{ 
    if (n <= 1) 
        return 0;  
    insertionSortRecursive( arr, n-1 );  
    int last = arr[n-1]; 
    int j = n-2; 
    while (j >= 0 && arr[j] > last) 
    { 
        comp++;
        arr[j+1] = arr[j]; 
        j--; 
    } 
    arr[j+1] = last;
    return comp; 
} 
   
void printArray(int arr[], int n) 
{ 
    printf("\nThe array is: ");
    for (int i=0; i < n; i++) 
        printf("%d ",arr[i]); 
} 
  
int main() 
{ 
    int arr[100]; 
    int n,comp=0;
    printf("\nEnter the value of number of elemnts in array: ");
    scanf("%d",&n); 
    comp=insertionSortRecursive(arr, n,comp); 
    printArray(arr, n); 
    printf("\nThe number of comaprisons is: %d\n",comp);
    return 0; 
} 
