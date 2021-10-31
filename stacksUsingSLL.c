#include <stdio.h>
#include <stdlib.h>

int main() {
	int op, x;
	while(1) {	
		printf("1.Push 2.Pop 3.Display 4.Is Empty 5.Peek 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d", &x);
				push(x);
				break;
			case 2:
				pop();
				break;
			case 3: 
				display();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				peek();
				break;
			case 6: 
				exit(0);
		}
	}
}

typedef struct stack
{
	int no;
	struct stack *next;
}node;

node *top = NULL;

void push(int x)
{
	node *temp;
	temp = (node *)malloc(sizeof(struct stack));
	temp -> no = x;
	temp -> next = top;
	top = temp;
	printf("Successfully pushed.\n");
}
void pop()
{
	node *ptr;
	if(top == NULL)
	{
		printf("Stack is underflow.\n");
		return;
	}
	printf("Popped value = %d\n", top->no);
	ptr = top;
	top = top -> next;
	free(ptr);
}
void display()
{
	node *ptr;
	ptr = top;
	if(tp == NULL)
	{
		printf("Stack is empty.\n");
	}
	else
	{
		printf("Elements of the stack are : ");
		while(ptr != NULL)
		{
			printf("%d ", ptr -> no);
			ptr = ptr -> next;
		}
		printf("\n");
	}
}
void isEmpty()
{
	if(top == NULL)
	{
		printf("Stack is empty.\n");
		return;
	}
	printf("Stack is not empty.\n");
}
void peek()
{
	if(top == NULL)
	{
		printf("Stack is underflow.\n");
		return;
	}
	printf("Peek value = %d\n", top -> no);
}