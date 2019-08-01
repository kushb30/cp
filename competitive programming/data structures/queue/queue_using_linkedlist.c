//Name-Kushagra Bansal
//Roll no 18MA20022
//implementing queue using linked list


#include <stdio.h>
#include <stdlib.h>
//defining structure
typedef struct node
{
	int info;
	node *link;
}node;

node *rear=NULL;
//function to check whether queue is empty or not
int isempty(node *head)
{
	if(head==NULL) return 1;
	else return 0;
}
//returns the first element in the queue
void front(node *head)
{
	if(isempty(head)) printf("The queue is empty\n");
	else printf("The first element in queue is: %d\n",head->info);
}
//add a new element to queue
node *EnQueue(node *head,int data)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->info=data;
	if(head==NULL)
	{
		temp->link=head;
		head=temp;
		rear=head;
	}
	else 
	{
		rear->link=temp;
		temp->link=NULL;
		rear=temp;
	}
	printf("%d inserted in the Queue\n",data);
	return head;
}
//delete the first element from the queue
node *DeQueue(node *head)
{
	if(isempty(head)) 
	{
		rear=NULL;
		printf("The queue is empty\n");
		return head;
	}
	node *temp;
	temp=head;
	head=head->link;
	printf("The data on the dequeued from the queue is: %d\n",temp->info);
	free(temp);
	return head;
	
}

int main()
{
	node *head=NULL;
	int choice,data;
	do
	{
		printf("Enter 1 to insert in the queue\n");
		printf("Enter 2 to delete from the queue\n");
		printf("Enter 3 to see first value in the queue\n");
		printf("Enter 4 to exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1:
				printf("Enter the data to be inserted: ");
				scanf("%d",&data);
				printf("\n");
				head=EnQueue(head,data);
				break;
			case 2:
				head=DeQueue(head);
				break;
			case 3:
				front(head);
				break;	
			case 4:
				printf("Exited\n");
				break;
			default:
				printf("Invalid choice\n");
				break;	
		}
	}while(choice!=4);
	return 0;
}
