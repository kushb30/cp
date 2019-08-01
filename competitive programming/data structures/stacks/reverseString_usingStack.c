//Name-Kushagra Bansal
//Roll no 18MA20022
//reversing string using stack


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//defining structure
typedef struct node
{
	char info;
	node *link;
}node;
//pushing a element in the stack
node *push(node *head,char data)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->info=data;
	temp->link=head;
	head=temp;
	return head;
}
//checking whether the stack is empty
int isempty(node *head)
{
	if(head==NULL) return 1;
	else return 0;
}
//return the topmost element in the stack
char top(node *head)
{
	return head->info;
}
//deletes the top element in the stack
node *pop(node *head)
{
	if(isempty(head))
	{
		return head;
	}
	node *temp;
	temp=head;
	head=head->link;
	printf("%c",top(temp));
	free(temp);
	return head;
}


int main()
{
	node *head=NULL;
	char array[100];
	printf("Enter a string\n");
	scanf("%s", array);
	int len;
	//calculating length of string
	for(int i = 0; array[i] != '\0'; ++i) len=i;
	for(int i=0;i<=len;i++)
		head=push(head,array[i]);
	printf("The reversed string is: ");
	for(int i=0;i<=len;i++)
		head=pop(head);
	printf("\n");
	return 0;
}
