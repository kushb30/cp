#include <bits/stdc++.h>
using namespace std;
struct node{
	struct node *prev,*next;
	int info;
};
struct node *addtoemp(struct node *start,int data){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->prev=NULL;
	temp->next=NULL;
	start=temp;
	return start;
}
struct node *addatbeg(struct node *start,int data){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->prev=NULL;
	temp->next=start;
	start->prev=temp;
	start=temp;
	return start;
}

struct node *addtoend(struct node*start,int data){
	struct node *temp,*ptr;
	ptr=start;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	while(ptr->next!=NULL) {
		ptr=ptr->next;
	}
	ptr->next=temp;
	temp->next=NULL;
	temp->prev=ptr;
	return start;
}
struct node *create_list(struct node*start){
	int size,data;
	cout<<"Enter the number of elements want to be added "<<endl;
	cin>>size;
	cout<<"Enter the value of first data "<<endl;
	cin>>data;
	start=addtoemp(start,data);
	for(int i=0;i<size-1;i++){
		cout<<"Enter the value of data you want to add "<<endl;
		cin>>data;
		start=addtoend(start,data);
	}
	return start;
}
struct node *addatpos(struct node *start,int data,int pos){
	struct node *temp,*ptr;
	int count=0;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	ptr=start;
	while(count!=pos-2){
		ptr=ptr->next;
		count++;
	}
	temp->prev=ptr;
	temp->next=ptr->next;
	ptr->next=temp;
	return start;
}
struct node *del(struct node *start,int data){
	struct node *ptr=start,*temp;
	if(start==NULL) cout<<"The list is empty "<<endl;
	else if(start->info==data){
		temp=start;
		start=start->next;
		free(temp);
		return start;
	}
	else{
		while(ptr->next!=NULL){
			if(ptr->info==data){
				temp=ptr;
				ptr->prev->next=temp;
				free(temp);
				return start;
			}
			ptr=ptr->next;
		}
	}
	cout<<"Data not found in the list "<<endl;
	return start;
}
void display(struct node *start){
	struct node *ptr;
	ptr=start;
	if(start==NULL) cout<<"The list is empty "<<endl;
	else{
		cout<<"The list is "<<endl;
		while(ptr!=NULL){
			cout<<ptr->info<<" ";
			ptr=ptr->next;
		}
		cout<<endl;
	}
}
struct node *reverse(struct node *start){
	struct node *ptr=start,*temp;
	temp=ptr->next;
	ptr->next=NULL;
	ptr->prev=temp;
	while(temp!=NULL) {
		temp->prev=temp->next;
		temp->next=ptr;
		ptr=temp;
		temp=temp->prev;
	}
	start=ptr;
	return start;
}
int main(){
	struct node *start=NULL;
	int choice,data,pos;
	do{
			cout<<"Enter 1 to create list "<<endl;
			cout<<"Enter 2 to displat the list "<<endl;
			cout<<"Enter 3 to add at beginning "<<endl;
			cout<<"Enter 4 to add to an empty list "<<endl;
			cout<<"Enter 5 to add at end "<<endl;
			cout<<"Enter 6 to add at position in between the list "<<endl;
			cout<<"Enter 7 to delete a data from the list "<<endl;
			cout<<"Enter 8 to reverse the list "<<endl;
			cout<<"Enter 9 to exit "<<endl;
			cout<<"Enter your choice "<<endl;
			cin>>choice;
			switch(choice){
				case 1:
					start=create_list(start);
					break;
				case 2:
					display(start);
					break;
				case 3:
					cout<<"Enter the value of data to be added "<<endl;
					cin>>data;
					start=addatbeg(start, data);
					break;
				case 4:
					cout<<"Enter the value of data to be added "<<endl;
					cin>>data;
					start=addtoemp(start,data);
					break;
				case 5:
					cout<<"Enter the value of data to be added "<<endl;
					cin>>data;
					start=addtoend(start,data);
					break;
				case 6:
					cout<<"Enter the value of data to be added "<<endl;
					cin>>data;
					cout<<"Enter the position at which data should be added "<<endl;
					cin>>pos;
					start=addatpos(start,data,pos);
					break;
				case 7:
					cout<<"Enter the value to be deleted "<<endl;
					cin>>data;
					start=del(start,data);
					break;
				case 8:
					start=reverse(start);
					break;
				case 9:
					cout<<"Thank you "<<endl;
					break;
				default :
					cout<<"Wrong choice "<<endl;
					break;	
			}
	}while(choice!=9);
	return 0;
}