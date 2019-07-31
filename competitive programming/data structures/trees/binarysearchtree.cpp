#include <bits/stdc++.h>
using namespace std;

struct tree
{
	struct tree *lchild;
	int info;
	struct tree *rchild;
};

int bstisempty(struct tree *root)
{
	if(root==NULL)
		return 1;
	else 
		return 0;
}

struct tree *search(struct tree *root,int data)
{
	if(bstisempty(root))
	{
		cout<<"Data not found"<<endl;
		return root;
	}
	if(data>root->info)
		return search(root->rchild,data);
	else if(data<root->info)
		return search(root->lchild,data);
	else
		return root;
}

struct tree *insert(struct tree *root,int data)
{
	struct tree *chk,*ptr=root,*temp,*q;
	temp=(struct tree *)malloc(sizeof(struct tree));
	temp->info=data;
	temp->lchild=NULL;
	temp->rchild=NULL;
	if(root==NULL)
	{
		root=temp;
		return root;
	}
	chk=search(root,data);
	if(chk!=NULL)
	{
		cout<<"Data already exists"<<endl;
		return root;
	}
	while(ptr!=NULL)
	{
		q=ptr;
		if(data>ptr->info)
			ptr=ptr->rchild;
		else
			ptr=ptr->lchild;
	}
	if(q->info>data)
		q->lchild=temp;
	else
		q->rchild=temp;
	cout<<"Data inserted successfully"<<endl;
	return root;
}

struct tree *maximumval(struct tree *root)
{
	struct tree *ptr=root,*q;
	if(bstisempty(root))
	{
		cout<<"BInary search tree in empty"<<endl;
		return root;
	}
	while(ptr!=NULL)
	{
		q=ptr;
		ptr=ptr->rchild;
	}
	return q;
}

struct tree *minimumval(struct tree *root)
{
	struct tree *ptr=root,*q;
	if(bstisempty(root))
	{
		cout<<"BInary search tree in empty"<<endl;
		return root;
	}
	while(ptr!=NULL)
	{
		q=ptr;
		ptr=ptr->lchild;
	}
	return q;
}

int height(struct tree *ptr)
{
	int h_left,h_right;
	if(ptr==NULL)
		return 0;
	h_left=height(ptr->lchild);
	h_right=height(ptr->rchild);
	if(h_right>h_left)
		return 1+h_right;
	else
		return 1+h_left;
}

void preorder(struct tree *ptr)
{
	struct tree *temp;
	int tmp;
	stack <struct tree *> s;
	s.push(ptr);
	while(s.size())
	{
		temp=s.top();
		s.pop();
		if(temp->rchild!=NULL)
			s.push(temp->rchild);
		if(temp->lchild!=NULL)
			s.push(temp->lchild);
		cout<<temp->info<<" ";
	}
	cout<<endl;
}

void postorder(struct tree *ptr)
{
	struct tree *q=ptr;
	int tmp;
	stack <struct tree *> s;
	while(1)
	{
		while(ptr->lchild!=NULL)
		{
			s.push(ptr);
			ptr=ptr->lchild;
		}
		while(ptr->rchild==NULL || ptr->rchild==q)
		{
			cout<<ptr->info<<" ";
			q=ptr;
			if(s.size()==0)
				return;
			ptr=s.top();
			s.pop();
		}
		s.push(ptr);
		ptr=ptr->rchild;
	}
	cout<<endl;
}

void inorder(struct tree *ptr)
{
	struct tree *q=ptr;
	int tmp;
	stack <struct tree *> s;
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

struct tree *del(struct tree *root,int data)
{
	struct tree *ptr=root,*q=NULL;
	if(bstisempty(root))
	{
		cout<<"The tree is empty"<<endl;
		return root;
	}
	while(1)
	{
		if(ptr==NULL)
		{
			cout<<"Data not exists in tree"<<endl;
			return root;
		}
		if(ptr->info==data) 
			break;
		else if(ptr->info>data)
		{
			q=ptr;
			ptr=ptr->lchild;
		}
		else
		{
			q=ptr;
			ptr=ptr->rchild;
		}

	}
	if(ptr->rchild==NULL && ptr->lchild==NULL)
	{
		if(q->lchild==ptr)
			q->lchild=NULL;
		else
			q->rchild=NULL;
		free(ptr);
	}
	else if(ptr->rchild==NULL && ptr->lchild!=NULL)
	{
		if(q->lchild==ptr)
			q->lchild=ptr->lchild;
		else
			q->rchild=ptr->lchild;
		free(ptr);
	}
	else if(ptr->rchild!=NULL && ptr->lchild==NULL)
	{
		if(q->lchild==ptr)
			q->lchild=ptr->rchild;
		else
			q->rchild=ptr->rchild;
		free(ptr);
	}
	else
	{
		struct tree *temp=ptr->rchild,*pretemp=ptr;
		while(temp->lchild!=NULL)
		{
			pretemp=temp;
			temp=temp->lchild;
		}
		ptr->info=temp->info;
		if(temp->rchild==NULL && temp->lchild==NULL)
		{
			if(pretemp->lchild==temp)
				pretemp->lchild=NULL;
			else
				pretemp->rchild=NULL;

			free(temp);
		}
		else if(temp->rchild==NULL && temp->lchild!=NULL)
		{
			if(pretemp->lchild==temp)
				pretemp->lchild=temp->lchild;
			else
				pretemp->rchild=temp->lchild;
			free(temp);s
		}
		else if(temp->rchild!=NULL && temp->lchild==NULL)
		{
			if(pretemp->lchild==temp)
				pretemp->lchild=temp->rchild;
			else
				pretemp->rchild=temp->rchild;
			free(temp);
		}
	}
	return root;
}

int main()
{
	struct tree *root=NULL,*dataadd;
	int choice,data;
	do
	{
		cout<<endl;
		cout<<"Press 0 to exit"<<endl;
		cout<<"Press 1 to search"<<endl;
		cout<<"Press 2 to insert"<<endl;
		cout<<"Press 3 for delete"<<endl;
		cout<<"Press 4 for preorder traversal"<<endl;
		cout<<"Press 5 for postorder traversal"<<endl;
		cout<<"Press 6 for inorder traversal"<<endl;
		cout<<"Press 7 for hieght of the tree"<<endl;
		cout<<"Pess 8 to find maximum in binary search tree"<<endl;
		cout<<"Pess 9 to find minimum in binary search tree"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		cout<<endl;
		switch(choice)
		{
			case 0:
				cout<<"Exited"<<endl;
				break;
			case 1:
				cout<<"Enter the data to be searched: ";
				cin>>data;
				cout<<endl;
				dataadd=search(root,data);
				if(dataadd!=NULL)
					cout<<"Data exists"<<endl;
				break;
			case 2:
				cout<<"Enter data to be inserted: ";
				cin>>data;
				cout<<endl;
				root=insert(root,data);
				break;
			case 3:
				cout<<"Enter the data to be deleted: ";
				cin>>data;
				cout<<endl;
				root=del(root,data);
				break;
			case 4:
				preorder(root);
				break;
			case 5:
				postorder(root);
				break;
			case 6:
				inorder(root);
				break;
			case 7:
				cout<<"The height of the tree is: "<<height(root)<<endl;
				break;
			case 8:
				dataadd=maximumval(root);
				if(dataadd!=NULL)
					cout<<"The maximum value is: "<<dataadd->info<<endl;
				break;
			case 9:
				dataadd=minimumval(root);
				if(dataadd!=NULL)
					cout<<"The minimum value is: "<<dataadd->info<<endl;
				break;
			default:
				cout<<"Wrong choice"<<endl;
				break;	
		}
	}while(choice!=0);
	return 0;
}