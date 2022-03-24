package Unit_1;

import java.util.*;

public class MergeSort {

	static void print(int a[])
	{
		for(int x : a)
			System.out.print(x + " ");
		System.out.println();
	}
	
	static void merge(int a[], int low, int mid, int high)
	{
		int temp[] = new int[high - low + 1];
		int i = low, j = mid + 1, k = 0;
		while(i <= mid && j <= high)
		{
			if(a[i] < a[j])
				temp[k++] = a[i++];
			else
			
				temp[k++] = a[j++];
		}
		while(i <= mid)
		{
			temp[k++] = a[i++];
		}
		while(j <= high)
		{
			temp[k++] = a[j++];
		}
		for(i = low, k = 0; i <= high; i++, k++)
		{
			a[i] = temp[k];
		}
	}
	
	static void sort(int a[], int low, int high)
	{
		if(low < high)
		{
			int mid = (low + high) / 2;
			sort(a, low, mid);
			sort(a, mid + 1, high);
			merge(a, low, mid, high);
			print(a);
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter array size : ");
		int n = sc.nextInt();
		int a[] = new int[n];
		System.out.print("Enter array elements : ");
		for(int i = 0; i < n; i++)
			a[i] = sc.nextInt();
		System.out.print("Array before Sort : ");
		print(a);
		long start = System.nanoTime();
		sort(a, 0, n - 1);
		long end = System.nanoTime();
		System.out.print("Array afer sort : ");
		print(a);
		System.out.println("Time COmplexity =  " + (end - start)*Math.pow(10, -9) + "Sec");
		sc.close();
	}

}
