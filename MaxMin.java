package Unit_1;
import java.util.*;
class Pair
{
	int min, max;
}

public class MaxMin {
	
	static void Iterative(int a[])
	{
		int max, min;
		max = min = a[0];
		for(int i = 1; i < a.length; i++)
		{
			if(a[i] > max)
				max = a[i];
			else if(a[i] < min)
			{
				min = a[i];
			}
		}
		System.out.println("MAX = " + max + "\nMIN = " + min);
	}
	
	static Pair Recursive(int a[], int low, int high)
	{
		Pair mm = new Pair();
		Pair m1 = new Pair();
		Pair m2 = new Pair();
		if(low == high)
		{
			mm.max = mm.min = a[low];
			return mm;
		}
		else if(low == high - 1)
		{
			if(a[low] < a[high])
			{
				mm.max = a[high];
				mm.min = a[low];
			}
			else
			{
				mm.max = a[low];
				mm.min = a[high];
			}
			return mm;
		}
		else
		{
			int mid = (low + high) / 2;
			m1 = Recursive(a, low, mid);
			m2 = Recursive(a, mid + 1, high);
			if(m1.min < m2.min)
			{
				mm.min = m1.min;
			}
			else
			{
				mm.min = m2.min;
			}
			if(m1.max < m2.max)
			{
				mm.max = m2.max;
			}
			else
			{
				mm.max = m1.max;
			}
		}
		return mm;
	}
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter array size : ");
		int n = sc.nextInt();
		int a[] = new int[n];
		System.out.print("Enter array : ");
		for(int i = 0; i < n; i++)
			a[i] = sc.nextInt();
		long s1 = System.nanoTime();
		Iterative(a);
		long e1 = System.nanoTime();
		System.out.println("Time complexity for iterative = " + (e1 - s1)*Math.pow(10, -9) + " SEC");
		long s2 = System.nanoTime();
		Pair mm = Recursive(a, 0, n-1);
		System.out.println("Max = " + mm.max + "\nMin = " + mm.min);
		long e2 = System.nanoTime();
		System.out.println("Time complexity for recursive = " + (e2 - s2)*Math.pow(10, -9) + " SEC");
		
		sc.close();
	}
}
