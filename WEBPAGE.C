#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	struct node *prev;
	char data[30];
	struct node *next;
};
struct node *header,*tail;
void addNode();
void viewNode();
void viewHistory();
void goBack();
void goFront();
int top=0;
char stack[30][20];
void main()
{
	int a,b;
	char ch[30];
	clrscr();
	do
	{
		printf("Enter your choice \n1 for searching new information \n2 for viewing the current Information \n3 for viewing the history \n4 to go back \n5 to go front\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:		addNode();
					break;
			case 2:         viewNode();
					break;
			case 3:         viewSearchHistory();
					break;
			case 4:         goBack();
					break;
			case 5:		goFront();
					break;
			default:	printf("Invalid choice");
					break;
		}
		printf("If you want to continue press 1 else 0\n");
		scanf("%d",&b);
	}
	while(b!=0);
}
void addNode()
{
	struct node *before,*after,*temp;
	temp=(struct node*)malloc(1*sizeof(struct node));
	printf("Enter the Data to Search \n");
	scanf("%s",temp->data);
	if(header==NULL)
	{
		header=temp;
		tail=header;
		tail->prev=NULL;
	}
	else
	{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
		tail->next=NULL;
	}
	strcpy(stack[top],tail->data);
	top++;
}
void viewNode()
{
	printf("Current Information is ");
	puts(tail->data);
}
void viewSearchHistory()
{
	// Using Stack Data Structure
	int i;
	printf("Your History is : \n");
	for(i=top-1;i>=0;i--)
	{
		puts(stack[i]);
	}
}
void goBack()
{

	tail=tail->prev;
	printf(" Moved Back\n");
	strcpy(stack[top],tail->data);
	top++;
}
void goFront()
{
	if(tail->next==NULL)
	{
		printf("Moving Forward is not Possible\n");
	}
	else
	{
		tail=tail->next;
		printf("Moved Forward\n");
		strcpy(stack[top],tail->data);
		top++;
	}
}