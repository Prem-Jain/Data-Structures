#include<stdio.h>
void main() {
	int a[20], i, n, j, temp;
	printf("Enter value of n : ");
	scanf("%d", &n);
	// Write the for loop to read array elements
	for(i = 0; i < n; i++)
	{
		printf("Enter element for a[%d] : ", i);
		scanf("%d", &a[i]);
	}
	printf("Before sorting the elements in the array are\n");
	// Write the for loop to display array elements before sorting
	for(i = 0; i < n; i++)
	{
		printf("Value of a[%d] = %d\n", i, a[i]);
	}
	//Write the code to sort elements
	for(i = 1; i < n; i++)
	{
		temp = a[i];
		for(j = i; j > 0; j--)
		{
			if(a[j - 1] > temp)
			{
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
	printf("After sorting the elements in the array are\n");
	// Write the for loop to display array elements after sorting
	for(i = 0; i < n; i++)
	{
		printf("Value of a[%d] = %d\n", i, a[i]);
	}
}