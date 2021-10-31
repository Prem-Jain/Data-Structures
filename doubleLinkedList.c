#include<stdio.h>
#include<stdlib.h>
typedef struct DLL
{
	struct DLL *lptr;
	int no;
	struct DLL *rptr;
}node;

node *left = NULL, *right = NULL;

void insert();
void deletion();
void display();

void main()
{
	int ch;
	while(1)
	{
		printf("Operations on doubly linked list\n");
		printf("1. Insert \n2.Remove\n3. Display\n0. Exit\n");
		printf("Enter Choice 0-4? : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 0: exit(0);
			case 1: insert();break;
			case 2: deletion();break;
			case 3: display();
		}
	}
}
void insert()
{
	node *p,*ptr;
	p = malloc(sizeof(node));
	printf("Enter number: ");
	scanf("%d", &p->no);
	if(left == NULL)
	{
		 p -> lptr = p -> rptr = NULL;
		 left = right = p;
		 return;
	}
	if(p -> no <= left -> no)
	{
		p -> lptr = NULL;
		p -> rptr = left;
		left -> lptr = p;
		left = p;
		return;
	}
	if(p -> no > right -> no)
	{
		p -> lptr = right;
		p -> rptr = NULL;
		right -> rptr = p;
		right = p;
		return;
	}
	ptr = left -> rptr;
	{
		while(ptr != right && p -> no > ptr -> no)
		{
			ptr = ptr -> rptr;
		}
		p -> rptr = ptr;
		p -> lptr = ptr -> lptr;
		ptr -> lptr -> rptr = p;
		ptr -> lptr = p;
	}
}
void deletion()
{
	int rno;
	node *ptr;
	if(left == NULL)
	{
		printf("Underflow\n");
		return;
	}
	printf("Enter number to delete: ");
	scanf("%d", &rno);
	if(rno == left -> no)
	{
		if(left == right)
		{
			left = right = NULL;
			return;
		}
		ptr = left;
		left = left -> rptr;
		left -> lptr = NULL;
		free(ptr);
		return;
	}
	if(rno == right -> no)
	{
		ptr = right;
		right = right -> lptr;
		right -> rptr = NULL;
		free(ptr);
		return;
	}
	ptr = left -> rptr;
	while(ptr != right && rno > ptr -> no)
	{ 
		ptr = ptr -> rptr;
	}
	if(ptr == right || rno < ptr -> no)
	{
		printf("%d not found.\n", rno);
		return;
	}
	ptr -> rptr -> lptr = ptr -> lptr;
	ptr -> lptr -> rptr = ptr -> rptr;
	free(ptr);
}
void display()
{
	node *ptr;
	if(left == NULL)
	{
		printf("List is empty\n");
		return;
	}
	ptr = left;
	while(ptr != NULL)
	{
		printf("%d\t", ptr->no);
		ptr = ptr -> rptr;
	}
	printf("\n");
}














