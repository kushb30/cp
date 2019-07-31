#include <bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *lchild;
	int data;
	tree *rchild;
}tree;
int main()
{
	tree *root=NULL;
	int choice,r,lc,rc;
	do
	{
		cout<<"Enter 0 to exit"<<endl;
		cout<<"Enter 1 to insert"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 0:
				break;
			case 1:
			
				break;
			default:
				break;
		}
	}while(choice!=0);
	return 0;
}