#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int no;
	char name[50];
	struct student *next;
}node;

node *first=NULL;

void insert();
void deletion();
void display();

void main()
{
	int ch;
	do
	{
		printf("1.Insert 2.Delete 3.Display 4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: insert();break;
			case 2: deletion();break;
			case 3: display();
		}
	}while(ch < 4);
}
void insert()
{
	node *p, *save, *ptr;
	p=malloc(sizeof(node));
	printf("Enter roll no and name of the student:");
	scanf("%d%s", &p -> no, p -> name);
	printf("Number Inserted\n");
	if(first == NULL)
	{
		p -> next = NULL;
		first = p;
		return;
	}
	if(p -> no < first -> no)
	{
		p -> next = first;
		first = p;
		return;
	}
	save = first;
	ptr = first -> next;
	while(ptr != NULL && ptr -> no < p -> no)
	{
		save = ptr;
		ptr = ptr -> next;
	}	
	save -> next = p;
	p -> next = ptr;
}
void deletion()
{
	node *temp, *ptr;
	int roll;
	if(first == NULL)
	{
		printf("Underflow\n");
		return;
	}
	printf("Enter roll no to be deleted");
	scanf("%d", &roll);
	if(roll < first -> no)
	{
		printf("Number not found\n");
		return;
	}
	if(first -> no == roll)
	{
		ptr = first;
		first = first -> next;
		printf("Number deleted\n");
		free(ptr);
		return;
	}
	temp = first;
	ptr = first -> next;
	while(ptr != NULL && roll > ptr -> no)
	{
		temp = ptr;
		ptr = ptr -> next;
	}
	if(ptr == NULL || roll < ptr -> no)
	{
		printf("Number not found\n");
		return;
	}
	temp -> next = ptr -> next;
	printf("Number deleted\n");
	free(ptr);
}
void display()
{
	node *ptr;
	if(first == NULL)
	{
		printf("List is empty\n");
		return;
	}
	ptr = first;
	while(ptr != NULL)
	{
		printf("%d %s\n", ptr -> no, ptr -> name);
		ptr = ptr -> next;
	}
	free(ptr);
}