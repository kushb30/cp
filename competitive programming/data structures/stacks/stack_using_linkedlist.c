//Name-Kushagra Bansal
//Roll no 18MA20022
//implementing stack using linked list


#include <stdio.h>
#include <stdlib.h>
//defining structure
typedef struct node
{
	int info;
	node *link;
}node;
//pushing a element in the stack
node *push(node *head,int data)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->info=data;
	temp->link=head;
	head=temp;
	printf("%d inserted in the stack\n",data);
	return head;
}
//checking whether the stack is empty
int isempty(node *head)
{
	if(head==NULL) return 1;
	else return 0;
}
//deletes the top element in the stack
node *pop(node *head)
{
	if(isempty(head))
	{
		printf("The stack is empty\n");
		return head;
	}
	node *temp;
	temp=head;
	head=head->link;
	printf("The data onthe top of the stack is: %d\n",temp->info);
	free(temp);
	return head;
}
//return the topmost element in the stack
void top(node *head)
{
	if(isempty(head)) printf("The stack is empty\n");
	else printf("The topmost element in stack is: %d\n",head->info);
}

int main()
{
	node *head=NULL;
	int choice,data;
	do
	{
		printf("Enter 1 to insert in the stack\n");
		printf("Enter 2 to delete from the stack\n");
		printf("Enter 3 to see top value in the stack\n");
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
				head=push(head,data);
				break;
			case 2:
				head=pop(head);
				break;
			case 3:
				top(head);
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
