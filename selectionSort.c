#include<stdio.h>
void main() {
	int a[20], i, n, j, small, index;
	printf("Enter value of n : ");
	scanf("%d", &n);
	// Write the code to read an array elements
	for(i = 0; i < n; i++)
	{
		printf("Enter element for a[%d] : ",i);
		scanf("%d", &a[i]);
	}
	printf("Before sorting the elements in the array are\n");
	// Write the code to print the given array elements before sorting
	for(i = 0; i < n; i++)
		printf("Value of a[%d] = %d\n", i, a[i]);
	// Write the code for selection sort smallest element method
	for(i = 0; i < n - 1; i++)
	{
		index = i;
		small = a[i];
		for(j = i + 1; j < n; j++)
		{
			if(a[index] > a[j])
			{
				index = j;
				small = a[j];
			}
		}
		a[index] = a[i];
		a[i] = small;
	}
	printf("After sorting the elements in the array are\n");
	// Write the code to print the given array elements after sorting
	for(i = 0; i < n; i++)
		printf("Value of a[%d] = %d\n", i, a[i]);
}