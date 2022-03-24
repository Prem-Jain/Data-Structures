package Unit_1;

import java.util.*;

public class BinSearch1 {
	
	/*public static int sizeof(int i) { return 4; } 
    public static int sizeof(long l) { return 8; }
    public static int sizeof(int a[]) { return a.length*4;}
    public static int sizeof(int a[], int l, int u) { return (u - l + 1)*4;}*/
	
	static void BSearchI(int a[], int x)
	{
		//int space = 0;
		int low = 0, high = a.length - 1;
		while(low <= high)
		{
			int mid = (low + high) / 2;
			if(x == a[mid])
			{
				System.out.println("Element found at index " + mid);
				//space = space + sizeof(a) + sizeof(x) + sizeof(mid) + sizeof(high) + sizeof(low);
				//System.out.println("Space Complexity = " + space);
				return;
			}
			else if(x < a[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		System.out.println("Element not found");
		//space = space + sizeof(a) + sizeof(x) + sizeof(mid) + sizeof(high) + sizeof(low);
		//System.out.println("Space Complexity = " + space);
		return;
	}
	static void BSearchR(int a[], int low, int high, int x/*, int space*/)
	{
			//space = space + sizeof(a, low, high) + sizeof(x) + sizeof(high) + sizeof(low);
			if(low <= high)
			{
				
				int mid = (low + high) / 2;
				//space = space + sizeof(mid);
				if(a[mid] == x)
				{
					System.out.println("Element found at index " + mid);
					//System.out.println("Space Complexity = " + space);
					return;
				}
				else if(x < a[mid])
				{
					BSearchR(a, low, mid - 1, x/*, space*/);
				}
				else
				{
					BSearchR(a, mid + 1, high, x/*, space*/);
				}
			}
			else
			{
				System.out.println("Element not found");
				//System.out.println("Space Complexity = " + space);
				return;
			}
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter array Size : ");
		int n = sc.nextInt();
		int a[] = new int[n];
		System.out.print("Enter array elements : ");
		for(int i = 0; i < n; i++)
			a[i] = sc.nextInt();
		Arrays.sort(a);
		System.out.print("Array is ");
		for(int b : a)
		{
			System.out.print(b + " ");
		}
		System.out.println();
		System.out.print("Enter the element to be searched : ");
		int x = sc.nextInt();
		long start = System.nanoTime();
		BSearchI(a, x);
		long end = System.nanoTime();
		System.out.println("Time Complexity for iterative = " +  (end - start)*Math.pow(10, -9) + "ns");
		long start1 = System.nanoTime();
		BSearchR(a, 0, n - 1, x/*, 0*/);
		long end1 = System.nanoTime();
		System.out.println("Time Complexity for recursive = " +  (end1 - start1)*Math.pow(10, -9) + "ns");
		sc.close();
	}
}