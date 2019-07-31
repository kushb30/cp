#include <bits/stdc++.h>
using namespace std;
struct node{
	int info;
	struct node *link;
};
struct node *addatbeg(struct node *start,int data){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=start;
	start=temp;
	return start;
}
struct node *addatend(struct node *start,int data){
	struct node *temp,*p;
	p=start;
	temp =(struct node *)malloc(sizeof(struct node));
	while(p->link!=NULL)	p=p->link;
	temp->info=data;
	p->link=temp;
	temp->link=NULL;
	return start;
}
struct node *create_list(struct node *start){
	int data,size;
	cout<<"Enter the size of list "<<endl;
	cin>>size;
	cout<<"Enter the value of first data "<<endl;
	cin>>data;
	start=addatbeg(start,data);
	for(int i=0;i<size-1;i++){
		cout<<"Enter the value of element "<<endl;
		cin>>data;
		start=addatend(start,data);
	}
	return start;
}
struct node *addatpos(struct node *start,int data,int pos){
	int count=0;
	struct node *temp,*prevpos=start;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	while(count!=pos-2){
		prevpos=prevpos->link;
		count++;
	}
	temp->link=prevpos->link;
	prevpos->link=temp;
	return start;
}
void display(struct node *start){
	struct node *p=start;
	cout<<"the list is "<<endl;
	if(p==NULL) cout<<"The list is empty "<<endl;
	else {
		while(p!=NULL){
			cout<<p->info<<" ";
			p=p->link;
		}
	}
	cout<<endl;
}
struct node *del(struct node *start,int data){
	struct node *temp,*p;
	if(start==NULL) cout<<"List is empty "<<endl;
	else if(start->info==data){
		temp=start;
		start=temp->link;
		free(temp);
		return start;
	}
	else {
		p=start;
		while(p->link!=NULL){
			if(p->link->info==data){
				temp=p->link;
				p->link=temp->link;
				free(temp);
				return start;
			}
			p=p->link;
		}
	}
	cout<<"Data not found int the list "<<endl;
	return start;
}
struct node *reverse(struct node *start){
	struct node *temp,*ptr=start,*prev=NULL;
	while(ptr!=NULL){
		temp=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=temp;
	}
	start=prev;
	return start;
}
int main(){
	int choice,data,pos;
	struct node *start=NULL;
	do{
		cout<<"Enter 1 to create list "<<endl;
		cout<<"Enter 2 to add data at begining "<<endl;
		cout<<"Enter 3 to add data at end "<<endl;
		cout<<"Enter 4 to check the list "<<endl;
		cout<<"Enter 5 to add data at position"<<endl;
		cout<<"Enter 6 to delete a data "<<endl;
		cout<<"Enter 7 to reverse the link list "<<endl;
		cout<<"Enter 8 to exit "<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				start=create_list(start);
				break;
			case 2:
				cout<<"Enter data to be added at begining ";
				cin>>data;
				start=addatbeg(start,data);
				break;
			case 3:
				cout<<"Enter data to be added at end ";
				cin>>data;
				start=addatend(start,data);
				break;
			case 4:
				display(start);
				break;
			case 5:
				cout<<"Enter the data to be added "<<endl;
				cin>>data;
				cout<<"Enter the position at which data should be added "<<endl;
				cin>>pos;
				start=addatpos(start,data,pos);
				break;
			case 6:
				cout<<"Enter the data to be deleted "<<endl;
				cin>>data;
				start=del(start,data);
				break;
			case 7:
				start=sreverse(start);
				break;					
			case 8:
				cout<<"Thank you "<<endl;
				break;
			default:
				cout<<"Wrong choice "<<endl;
				break;		
		}

	}while(choice!=8);
	return 0;
}