#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int a[50], n;
void  display()
{
	int i;
	printf("The array elements are ");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int partition(int lb, int ub)
{
	int i = lb, j = ub, pivot =  a[lb], temp;
	while(i < j)
	{
		while(a[i] <= pivot)
			i++;
		while(a[j] > pivot)
			j--;
		if(i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[lb];
	a[lb] = a[j];
	a[j] = temp;
	display();
	return j;
}

void quickSort(int lb, int ub)
{       if(lb < ub)
	{
		int pivot = partition(lb, ub);
		quickSort(lb, pivot - 1);
		quickSort(pivot + 1, ub);
	}
}
void main()
{
	int i;
	printf("Enter the number of the elements : ");
	scanf("%d", &n);
	printf("Enter array : ");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Before sort : Array elements are ");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	quickSort(0, n - 1);
	printf("After Sort : ");
	display();
	getch();
	clrscr();
}