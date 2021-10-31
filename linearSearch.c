#include<stdio.h>
void search(int [], int , int);
void main()
{
	int a[10], i, n, ele;
	char ch;
	printf("Enter number of elements:");
	scanf("%d", &n);
	printf("Enter array elements: ");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("The elements of the array are: ");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	do
	{
		printf("Enter searching element:");
		scanf("%d", &ele);
		search(a, n, ele);
		printf("Do you want to search another element?y/n: ");
		scanf(" %c", &ch);
	}while(ch == 'y' || ch == 'Y');
}
void search(int x[10], int n, int ele)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(x[i] == ele)
		{
			printf("Element found at index %d\n", i);
			break;
		}
	}
	if(i == n)
		printf("Element not found\n");
}