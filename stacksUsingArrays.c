include <stdio.h>
#include <stdlib.h>
#define STACK_MAX_SIZE 10

int stack[STACK_MAX_SIZE];
int top = -1;


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

void push(int x)
{
	if(top == STACK_MAX_SIZE - 1)
	{
		printf("Stack is overflow.\n");
		return;
	}
	stack[++top] = x;
	printf("Successfully pushed.\n");
}
void pop()
{
	if(top == -1)
	{
		printf("Stack is underflow.\n");
		return;
	}
	printf("Popped value = %d\n", stack[top--]);
}
void display()
{
	int i;
	if(top == -1)
	{
		printf("Stack is empty.\n");
		return;
	}
	printf("Elements of the stack are : ");
	for(i = top; i >= 0; i--)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}
void isEmpty()
{
	if(top == -1)
	{
		printf("Stack is empty.\n");
		return;
	}
	printf("Stack is not empty.\n");
}
void peek()
{
	if(top == -1)
	{
		printf("Stack is underflow.\n");
		return;
	}
	printf("Peek value = %d\n", stack[top]);
}