#include<stdio.h>
void read(int [],int);
void display(int [],int);
void merge(int [], int [], int [], int, int);
void main()
{
	int m, n, a[10], b[10], c[20];
	printf("Enter number of elements for array A: ");
	scanf("%d", &m);
	printf("Enter number of elements for array B: ");
	scanf("%d", &n);
	printf("Enter elements for A in ascending order: ");
	read(a, m);
	printf("Enter elements for B in ascending order: ");
	read(b, n);
	printf("The elements in array A are:");
	display(a, m);
	printf("The elements in array B are:");
	display(b, n);
	merge(c, a, b, m, n);
	printf("The merged elements in array C are: ");
	display(c, m + n);
}
void read(int x[10], int n)
{
	int i;
	for(i = 0; i < n; i++)
		scanf("%d", &x[i]);
}
void display(int x[10], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", x[i]);
	printf("\n");
}
void merge(int z[20], int x[10], int y[10], int m, int n)
{
	int i = 0, j = 0, k = 0;
	while(i < m && j < n)
	{
		if(x[i] < y[j])
			z[k++] = x[i++];
		else 
			z[k++] = y[j++];
	}
	while(j < n)
	{
		z[k++] = y[j++];
	}
	while(i < m)
	{
		z[k++] = x[i++];	
	}
}