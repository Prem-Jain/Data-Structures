#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 20
int a[MAXSIZE], n;
void insert()
{
	int ele, i, pos;
	printf("Enter element to be inserted : ");
	scanf("%d", &ele);
	printf("Enter the position(index) : ");
	scanf("%d", &pos);
	if(pos > n)
	{
		printf("Invalid position\n");
		return;
	}
	for(i = n - 1; i >= pos; i--)
	{
		a[i + 1] = a[i];
	}
	a[pos] = ele;
	n++;
}
void deletion()
{
	int i, pos;
	printf("Enter the position(index) to be deleted : ");
	scanf("%d", &pos);
	if(pos > n)
	{
		printf("Invalid position\n");
		return;
	}
	printf("The deleted element is %d\n", a[pos]);
	for(i = pos; i < n - 1; i++);
		a[i] = a[i + 1];
	n--;
}
void search()
{
	int i, key;
	printf("Enter element6 to be search : ");
	scanf("%d", &key);
	for(i = 0; i < n; i++)
	{
		if(a[i] == key)
		{
			printf("Element found at index %d\n", i);
			return;
		}
	}
	printf("Element not found\n");
}
void display()
{
	printf("Elements in the array are ");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void sort()
{	int i, j, temp;
	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - i -1; j++)
		{
			if(a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

}
void sec_largest()
{       sort();
	printf("Second largest = %d\n", a[n - 2]);
}
int isSquare(int x)
{
	int ivar;
	float fvar;
	fvar = sqrt((double)x);
	ivar = fvar;
	if(ivar == fvar)
		return x;
	else
		return 0;
}
void pos_sq_sum()
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += isSquare(a[i]);
	printf("The sum of the positive square in an array is %d\n", sum);
}
void miss_ele()
{
	int i, lr, ur, j;
	sort();
	printf("Enter the index range : ");
	scanf("%d%d", &lr, &ur);
	if(lr > ur)
	{
		printf("Invalid range\n");
		return;
	}
	printf("The missing numbers are ");
	for(i = lr; i < ur; i ++)
	{
		if(a[i + 1] - a[i] != 1)
		{
			for(j = 1; j < a[i + 1] - a[j]; j++)
			{
				printf("%d ", a[i] + j);
			}
		}
	}
	printf("\n");
}
void main()
{       clrscr();
	int ch;
	printf("Enter the size of the array : ");
	scanf("%d", &n);
	printf("Enter the elements of the array : ");
	for(int i = 0; i< n; i ++)
		scanf("%d", &a[i]);
	while(1)
	{
		printf("1.Insert\n2.Delete\n3.Display\n4.Search\n5.Second Largest\n6.Postive Square sum\n7.Missiing elements\n8.Exit\nEnter your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: insert();break;
			case 2: deletion();break;
			case 3: display();break;
			case 4: search();break;
			case 5: sec_largest();break;
			case 6: pos_sq_sum();break;
			case 7: miss_ele();break;
			case 8: exit(0);
		}
	}
}
