#include <bits/stdc++.h>
using namespace std;
void display(int heap[],int hsize)
{
	for(int i=1;i<=hsize;i++)
		cout<<heap[i]<<" ";
	cout<<endl;
}
void restoreup(int heap[],int *phsize,int data)
{
	int par,i;
	i=*phsize;
	par=i/2;
	while(heap[par]<data)
	{
		heap[i]=heap[par];
		i=par;
		par=i/2;
	}
	heap[i]=data;
}
void insert(int heap[],int *phsize,int data)
{
	(*phsize)++;
	heap[*phsize]=data;
	restoreup(heap,phsize,data);
}
void restoredown(int heap[],int *phsize)
{
	int key=heap[1];
	int lchild=2,i=1;
	int rchild=3;
	while(1)
	{
		if(rchild>*phsize)
			break;
		if(key>heap[lchild] && key>heap[rchild])
			break;
		if(heap[lchild]>key && key>heap[rchild])
		{
			heap[i]=heap[lchild];
			i=lchild;
		}
		else if(heap[lchild]<key && key<heap[rchild])
		{
			heap[i]=heap[rchild];
			i=rchild;
		}
		else
		{
			if(heap[rchild]>heap[lchild])
			{
				heap[i]=heap[rchild];
				i=rchild;
			}
			else
			{
				heap[i]=heap[lchild];
				i=lchild;
			}
		}
		lchild=2*i;
		rchild=2*i+1;
	}
	if(lchild==*phsize && heap[lchild]>key)
	{
		heap[i]=heap[lchild];
		i=lchild;
	}
	heap[i]=key;
}
void del(int heap[],int *phsize)
{
	int max=heap[1];
	heap[1]=heap[*phsize];
	(*phsize)--;
	restoredown(heap,phsize);
	cout<<"THe deleted item is: "<<max<<endl;
}
void buildheap(int heap[],int size)
{
	for(int i=2;i<=size;i++)
		restoreup(heap,&i,heap[i]);
}
int main()
{
	int heap[1000],hsize=0,data;
	heap[0]=9999999;
	int choice;
	do
	{
		cout<<"Press 1 to insert"<<endl;
		cout<<"Press 2 to Delete root"<<endl;
		cout<<"Press 3 to Display"<<endl;
		cout<<"Press 4 to Build Heap"<<endl;
		cout<<"Press 0 to Exit"<<endl;
		cout<<"Enter your choice";
		cin>>choice;
		cout<<endl;
		switch(choice)
		{
			case 0:
				cout<<"Exited"<<endl;
				break;
			case 1:
				cout<<"Enter the data to be inserted";
				cin>>data;
				cout<<endl;
				insert(heap,&hsize,data);
				break;
			case 2:
				del(heap,&hsize);
				break;
			case 3:
				display(heap,hsize);
				break;
			case 4:
				cout<<"Enter the size of array";
				cin>>data;
				cout<<endl;
				for(int i=1;i<=data;i++)
					cin>>heap[i];
				buildheap(heap,data);
				hsize=data;
				break;
			default:
				cout<<"Wrong choice"<<endl;
				break;
		}
	}while(choice!=0);
}