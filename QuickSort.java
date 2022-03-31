package Unit_1;

import java.util.*;

public class QuickSort {

	static void print(int a[])
	{
		for(int k : a)
			System.out.print(k + " ");
		System.out.println();
	}
	
	static int partition(int a[], int low, int high)
	{
		int i = low, j = high, temp, pivot = a[low];//pivot = a[high]
		while(i < j)
		{
			while(i <= high && a[i] <= pivot)
				i++;
			while(j >= low && a[j] > pivot) 
				j--;
			if(i < j)
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
				print(a);
			}
		}
		a[low] = a[j]; // a[high] = a[j + 1] 
		a[j] = pivot; // a[j + 1] = pivot
		print(a);
		return j; // j + 1
	}
	
	static void sort(int a[], int low, int high)
	{
		if(low < high)
		{
			int j = partition(a, low, high);
			sort(a, low, j - 1);
			sort(a, j + 1, high);
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Size : ");
		int n = sc.nextInt();
		int a[] = new int[n];
		System.out.print("Enter array elements : ");
		for(int  i = 0; i < n; i++)
			a[i] = sc.nextInt();
		System.out.print("Array before sort : ");
		print(a);
		long start = System.nanoTime();
		sort(a, 0, n - 1);
		long end = System.nanoTime();
		System.out.print("Array after sort : ");
		print(a);
		System.out.println("Time complexity = " + (end - start) * Math.pow(10, -9));
		
		sc.close();
	}

}
