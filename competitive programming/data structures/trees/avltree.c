#include <bits/stdc++.h>
using namespace std;
typedef struct tree
{
	tree *lchild;
	tree *rchild;
	int info;
	int bf;
}tree;

tree *leftrotation(tree *pptr)
{
	tree *aptr;
	aptr=pptr->rchild;
	pptr->rchild=aptr->lchild;
	aptr->lchild=pptr;
	return aptr;
}



tree *rightrotation(tree *pptr)
{
	tree *aptr;
	aptr=pptr->lchild;
	pptr->lchild=aptr->rchild;
	aptr->rchild=pptr;
	return aptr;
}

tree *insert_leftbalance(tree *pptr)
{
	tree *aptr,*bptr;
	aptr=pptr->lchild;
	if(aptr->bf==1)
	{
		pptr->bf=0;
		aptr->bf=0;
		pptr=rightrotation(pptr);
	}
	else
	{
		bptr=aptr->rchild;
		switch(bptr->bf)
		{
			case 0:
				aptr->bf=0;
				pptr->bf=0;
				break;
			case 1:
				aptr->bf=0;
				pptr->bf=-1;
				break;
			case -1:
				aptr->bf=1;
				pptr->bf=0;
				break;
		}
		bptr->bf=0;
		pptr->lchild=leftrotation(pptr->lchild);
		pptr=rightrotation(pptr);
	}
	return pptr;
}

tree *del_rightbalance(tree *pptr,int *add)
{
	tree *aptr,*bptr;
	aptr=pptr->rchild;
	if(aptr->bf==0)
	{
		pptr->bf=-1;
		aptr->bf=1;
		*add=0;
		pptr=leftrotation(pptr);
	}
	else if(aptr->bf=-1)
	{
		pptr->bf=0;
		aptr->bf=0;
		pptr=leftrotation(pptr);
	}
	else
	{
		bptr=aptr->lchild;
		switch(bptr->bf)
		{
			case 0:
				pptr->bf=0;
				aptr->bf=0;
				break;
			case 1:
				pptr->bf=0;
				aptr->bf=-1;
				break;
			case -1:
				pptr->bf=1;
				aptr->bf=0;
				break;
		}
		bptr->bf=0;
		pptr->rchild=rightrotation(aptr);
		pptr=leftrotation(pptr);
	}
	return pptr;
}

tree *insert_rightbalance(tree *pptr)
{
	tree *aptr,*bptr;
	aptr=pptr->rchild;
	if(aptr->bf==-1)
	{
		pptr->bf=0;
		aptr->bf=0;
		pptr=leftrotation(pptr);
	}
	else
	{
		bptr=aptr->lchild;
		switch(bptr->bf)
		{
			case 0:
				aptr->bf=0;
				pptr->bf=0;
				break;
			case 1:
				aptr->bf=-1;
				pptr->bf=0;
				break;
			case -1:
				aptr->bf=0;
				pptr->bf=1;
				break;
		}
		bptr->bf=0;
		pptr->rchild=rightrotation(pptr->rchild);
		pptr=leftrotation(pptr);
	}
	return pptr;
}

tree *del_leftbalance(tree *pptr,int *add)
{
	tree *aptr,*bptr;
	aptr=pptr->lchild;
	if(aptr->bf==0)
	{
		pptr->bf=1;
		aptr->bf=-1;
		*add=0;
		pptr=rightrotation(pptr);
	}
	else if(aptr->bf=1)
	{
		pptr->bf=0;
		aptr->bf=0;
		pptr=rightrotation(pptr);
	}
	else
	{
		bptr=aptr->rchild;
		switch(bptr->bf)
		{
			case 0:
				pptr->bf=0;
				aptr->bf=0;
				break;
			case 1:
				pptr->bf=-1;
				aptr->bf=0;
				break;
			case -1:
				pptr->bf=0;
				aptr->bf=1;
				break;
		}
		bptr->bf=0;
		pptr->lchild=leftrotation(aptr);
		pptr=rightrotation(pptr);
	}
	return pptr;
}

tree *insert_left_chk(tree *pptr,int *add)
{
	switch(pptr->bf)
	{
		case 0:
			pptr->bf=1;
			*add=1;
			break;
		case -1:
			pptr->bf=0;
			*add=0;
			break;
		case 1:
			pptr=insert_leftbalance(pptr);
			*add=0;
			break;
	}
	return pptr;
}

tree *del_left_chk(tree *pptr,int *add)
{
	switch(pptr->bf)
	{
		case 0:
			pptr->bf=-1;
			*add=0;
			break;
		case -1:
			pptr->bf=0;
			break;
		case 1:
			pptr=del_rightbalance(pptr,add);
			break;
	}
	return pptr;
}

tree *insert_right_chk(tree *pptr,int *add)
{
	switch(pptr->bf)
	{
		case 0:
			pptr->bf=-1;
			*add=1;
			break;
		case -1:
			pptr->bf=0;
			*add=0;
			break;
		case 1:
			pptr=insert_rightbalance(pptr);
			*add=0;
			break;
	}
	return pptr;
}

tree *del_right_chk(tree *pptr,int *add)
{
	switch(pptr->bf)
	{
		case 0:
			pptr->bf=1;
			*add=0;
			break;
		case 1:
			pptr->bf=0;
			break;
		case -1:
			pptr=del_leftbalance(pptr,add);
			break;
	}
	return pptr;
}

tree *insert(tree *pptr,int data)
{
	static int flag;
	if(pptr==NULL)
	{
		pptr=(tree *)malloc(sizeof(tree));
		pptr->lchild=NULL;
		pptr->info=data;
		pptr->rchild=NULL;
		pptr->bf=0;
		flag=1;
	}
	else if(pptr->info>data)
	{
		pptr->lchild=insert(pptr->lchild,data);
		if(flag==1)
			pptr=insert_left_chk(pptr,&flag);
	}
	else if(pptr->info<data)
	{
		pptr->rchild=insert(pptr->rchild,data);
		if(flag==1)
			pptr=insert_right_chk(pptr,&flag);
	}
	else
	{
		cout<<"Data already exists"<<endl;
		flag=0;
	}
	return pptr;		
} 

tree *del(tree *pptr,int data)
{
	tree *tmp,*succ;
	static int flag2;
	if(pptr==NULL)
	{
		cout<<"Data not exists"<<endl;
		flag2=0;
		return pptr;
	}
	else if(pptr->info>data)
	{
		pptr->lchild=del(pptr->lchild,data);
		if(flag2==1)
			pptr=del_left_chk(pptr,&flag2);
	}
	else if(pptr->info<data)
	{
		pptr->rchild=del(pptr->rchild,data);
		if(flag2==1)
			pptr=del_right_chk(pptr,&flag2);
	}
	else
	{
		if(pptr->lchild!=NULL && pptr->rchild!=NULL)
		{
			succ=pptr->rchild;
			while(succ->lchild!=NULL)
				succ=succ->lchild;
			pptr->info=succ->info;
			pptr->rchild=del(pptr->rchild,succ->info);
			if(flag2==1)
				pptr=del_right_chk(pptr,&flag2);
		}
		else
		{
			tmp=pptr;
			if(pptr->lchild!=NULL)
				pptr=pptr->lchild;
			else if(pptr->rchild!=NULL)
				pptr=pptr->rchild;
			else
				pptr=NULL;
			free(tmp);
			flag2=1;
		}
	}
	return pptr;
}

void inorder( tree *ptr)
{
	tree *q=ptr;
	int tmp;
	stack <tree *> s;
	while(1)
	{
		while(ptr->lchild!=NULL)
		{
			s.push(ptr);
			ptr=ptr->lchild;
		}
		while(ptr->rchild==NULL )
		{
			cout<<ptr->info<<" ";
			if(s.size()==0)
				return;
			ptr=s.top();
			s.pop();
		}
		cout<<ptr->info<<" ";
		ptr=ptr->rchild;
	}
	cout<<endl;
}

int main()
{
	tree *root=NULL;
	int choice,data;
	do
	{
		cout<<endl;
		cout<<"Press 0 to exit"<<endl;
		cout<<"Press 1 to insert"<<endl;
		cout<<"Press 2 to delete"<<endl;
		cout<<"Press 3 for inorder traversal"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		cout<<endl;
		switch(choice)
		{
			case 0:
				cout<<"Exited"<<endl;
				break;
			case 1:
				cout<<"Enter the data: ";
				cin>>data;
				cout<<endl;
				root=insert(root,data);
				break;
			case 2:
				cout<<"Enter the data: ";
				cin>>data;
				cout<<endl;
				root=del(root,data);
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