package Unit_1;

import java.util.*;

public class KnapSack {
	
	static void print(int a[])
	{
		for(int k : a)
			System.out.print(k + " ");
		System.out.println();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter number of objects : ");
		int n = sc.nextInt();
		int w[] = new int[n];
		int p[] = new int[n];
		for(int i = 0; i < n; i++)
		{
			System.out.print("Enter profit and weight : ");
			p[i] = sc.nextInt();
			w[i] = sc.nextInt();
		}
		System.out.print("Enter Knapsack weight : ");
		int m = sc.nextInt();
		for(int i = 0; i < n - 1; i++)
		{
			for(int j = 0; j < n - 1; j++)
			{
				if(((double)p[j] / (double)w[j]) < ((double)p[j + 1] / (double)w[j + 1]))
				{
					int temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
					temp = w[j + 1];
					w[j + 1] = w[j];
					w[j] = temp;
				}
			}
		}
		System.out.println("After sorting according to the p/w ratio");
		System.out.print("OBJECT : ");
		for(int i = 1; i <= n; i++)
		{
			System.out.print(i + " ");
		}
		System.out.println();
		System.out.print("PROFIT : ");
		print(p);
		System.out.print("WEIGHT : ");
		print(w);
		int k = 0;
		double sum = 0;
		while(k <  n && m > 0)
		{
			if(w[k] < m)
			{
				sum += p[k];
				m -= w[k];
			}
			else
			{
				sum += ((double)m / (double)w[k] * (double)p[k]);
				m = 0;
			}
			k++;
		}
		System.out.println("MAX PROFIT = " + sum);
		sc.close();
	}
}
