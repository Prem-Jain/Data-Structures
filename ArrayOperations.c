#include<stdio.h>
int n,ch;
void menu();
void create(int []);
void display(int []);
void insert(int []);
void delete(int []);
void main()
{
	int a[10];
	menu();
	while(ch < 5)
	{
		switch(ch)
		{
			case 1: create(a); break;
			case 2: display(a) ; break;
			case 3: insert(a) ; break;
			case 4: delete(a) ; break;
		}
		menu();
	}
}
void menu()
{
	printf("1.Create\n2.Display\n3.Insert\n4.Delete\n5.Exit\nEnter your choice : ");
	scanf("%d", &ch);
}
void create(int a[10])
{
	int i;
	printf("Enter the size of the array elements : ");
	scanf("%d", &n);
	printf("Enter the elements for the array : ");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
}
void display(int a[10])
{
	int i;
	printf("The array elements are : ");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void insert(int a[10])
{
	int i,pos,ele;
	printf("Enter the position(index) for the new element : ");
	scanf("%d", &pos);
	printf("Enter the element to be inserted : ");
	scanf("%d", &ele);
	if(pos > n)
	{
		printf("Invalid position.\n");
	}
	else
	{
		for(i = n - 1; i >= pos; i--)
			a[i + 1] = a[i];
		a[pos] = ele;
		n++;
	}
}
void delete(int a[10])
{
	int i, pos;
	printf("Enter the position(index) of the element to be deleted : ");
	scanf("%d", &pos);
	if(pos > n)
	{
		printf("Invalid position.\n");
	}
	else
	{
		printf("The deleted element is : %d\n", a[pos]);
		for(i = pos; i < n - 1; i++)
			a[i] = a[i + 1];
		n--;
	}
}