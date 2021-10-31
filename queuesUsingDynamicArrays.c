#include <stdio.h>
#include <stdlib.h>

int main() {
	int op, x;
	printf("Enter the maximum size of the circular queue : ");
	scanf("%d", &maxSize);
	initCircularQueue();
	while(1) {	
		printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
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
				exit(0);
		}
	}
}

int maxSize, *q, front =-1, rear= -1;
void initCircularQueue()
{
	q = (int *)malloc(maxSize * sizeof(int));
}
void enqueue(int x)
{
	if((rear + 1) % maxSize == front)
	{
		printf("Circular queue is overflow.\n");
		return;
	}
	if(front == -1)
		front = rear = 0;
	else
		rear = (rear + 1) % maxSize;
	*(q + rear) = x;
	printf("Successfully inserted.\n");
}
void dequeue()
{
	if(front == -1)
	{
		printf("Circular queue is underflow.\n");
		return;
	}
	printf("Deleted element = %d\n",*(q + front));
	if(front == rear)
		front = rear = -1;
	else
		front = (front + 1) % maxSize;
}
void display()
{
	int i;
	if(front == -1)
	{
		printf("Circular queue is empty.\n");
		return;
	}
	printf("Elements in the circular queue : ");
	if(front <= rear)
	{
		for(i = front; i <= rear; i++)
		{
			printf("%d ", *(q + i));
		}
	}
	else
	{
		for(i = front; i < maxSize; i++)
			printf("%d ", *(q + i));
		for(i = 0;i <= rear; i++)
			printf("%d ", *(q + i));
	}
	printf("\n");
}