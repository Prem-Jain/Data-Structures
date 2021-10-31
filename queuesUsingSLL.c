#include <conio.h>
#include <stdio.h>
#include<stdio.h>
#include<stdlib.h>

int main() {
	int op, x;
	while(1) {	
		printf("1.Enqueue 2.Dequeue 3.Display 4.Is Empty 5.Size 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d",&op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d",&x);
				enqueue(x);
				break;
			case 2: 
				dequeue();
				break;
			case 3: 
				display();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				size();
				break;
			case 6: exit(0);
		}
	}
}

typedef struct queue
{
	int no;
	struct queue *next;
}node;

node *front = NULL, *rear = NULL;

void enqueue(int x)
{
	node *p;
	p = malloc(sizeof(node));
	p -> no = x;
	p -> next = NULL;
	if(front == NULL)
	{
		p -> next = NULL;
		front = rear = p;
		printf("Successfully inserted.\n");
		return;
	}
	rear -> next = p;
	rear = p;
	printf("Successfully inserted.\n");
}
void dequeue()
{
	node *ptr;
	if(front == NULL)
	{
		printf("Queue is underflow.\n");
		return;
	}
	ptr = front;
	front = front -> next;
	if(front == NULL)
	{
		rear = NULL;
	}
	printf("Deleted value = %d\n", ptr -> no);
	free(ptr);
}
void display()
{
	node *ptr;
	if(front == NULL)
	{
		printf("Queue is empty.\n");
		return;
	}
	ptr = front;
	printf("Elements in the queue : ");
	while(ptr != NULL)
	{
		printf("%d ", ptr -> no);
		ptr = ptr -> next;
	}
	printf("\n");
}
void isEmpty()
{
	if(front == NULL)
	{
		printf("Queue is empty.\n");
		return;
	}
	printf("Queue is not empty.\n");
}
void size()
{
	node *ptr;
	int size = 0;
	if(front == NULL)
	{
		printf("Queue size : %d\n", size);
		return;
	}
	ptr = front;
	while(ptr != NULL)
	{
		size++;
		ptr = ptr -> next;
	}
	printf("Queue size : %d\n", size);
}