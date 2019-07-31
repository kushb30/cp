#include <bits/stdc++.h>
using namespace std;

struct tree
{
	struct tree *lchild;
	int info;
	struct tree *rchild;
	bool lthread;
	bool rthread;
};

struct tree *inordersucc(struct tree *ptr)
{
	if(ptr->rthread==true)
		return ptr->rchild;
	else
	{
		ptr=ptr->rchild;
		while(ptr->lchild!=NULL)
		{
			if(ptr->lthread==true)
				break;
			ptr=ptr->lchild;
		}
		return ptr;
	}
}

struct tree *inorderpred(struct tree *ptr)
{
	if(ptr->lthread==true)
		return ptr->lchild;
	else
	{
		ptr=ptr->lchild;
		while(ptr->rthread==false)
			ptr=ptr->rchild;
		return ptr;
	}
}

struct tree *insert(struct tree *ptr,int data)
{
	struct tree *tmp,*q=ptr,*root=ptr;
	int flag=0;
	tmp=(struct tree *)malloc(sizeof(struct tree));
	tmp->info=data;
	tmp->lthread=true;
	tmp->rthread=true;
	if(ptr==NULL)
	{
		tmp->rchild=NULL;
		tmp->lchild=NULL;
		return tmp;
	}
	while(1)
	{
		q=ptr;
		if(ptr->lthread==true && ptr->rthread==true)
			break;
		if(ptr->info==data)
			flag=1;
		else if(ptr->info>data)
		{
			if(ptr->lthread==false)	
				ptr=ptr->lchild;
			else
				break;
		}
		else 
		{
			if(ptr->rthread==false)
				ptr=ptr->rchild;
			else 
				break;
		}
	}
	if(flag)
	{
		cout<<"Data already exists"<<endl;
		return root;
	}
	if(q->info>data)
	{
		q->lthread=false;
		tmp->lchild=q->lchild;
		q->lchild=tmp;
		tmp->rchild=q;
	}
	else
	{
		q->rthread=false;
		tmp->rchild=q->rchild;
		q->rchild=tmp;
		tmp->lchild=q;
	}
	return root;
}

void inorder(struct tree *ptr)
{
	if(ptr==NULL)
	{
		cout<<"the tree is empty"<<endl;
		return;
	}
	while(ptr->lthread==false)
		ptr=ptr->lchild;
	while(ptr!=NULL)
	{
		cout<<ptr->info<<" ";
		ptr=inordersucc(ptr);
	}
	cout<<endl;
}

int main()
{
	struct tree *root=NULL;
	int choice,data;
	do
	{
		cout<<endl;
		cout<<"Press 0 to exit"<<endl;
		cout<<"Press 1 to insert"<<endl;
		cout<<"Press 3 for inorder traversal"<<endl;
		cout<<"Press 4 for preoreder traversal"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		cout<<endl;
		switch(choice)
		{
			case 0:
				cout<<"Exited"<<endl;
				break;
			case 1:
				cout<<"Enter the data to be inserted: ";
				cin>>data;
				cout<<endl;
				root=insert(root,data);
				break;
			case 3:
				inorder(root);
				break;
			default:
				cout<<"Wrong choice"<<endl;
				break;
		}
	}while(choice!=0);
	return 0;
}