package Unit_3;

import java.util.*;

public class Knapsack10 {
	
	static int knapsack(int W, int wt[], int val[], int n)
	{
		int i, w;
		int k[][] = new int[n + 1][W + 1];
		for(i = 0; i <= n; i++)
		{
			for(w = 0; w <= W; w++)
			{
				if(i == 0 || w == 0)
					k[i][w] = 0;
				else if(wt[i - 1] <= w)
					k[i][w] = Math.max(val[i - 1] + k[i - 1][w - wt[i - 1]], k[i - 1][w]);
				else
					k[i][w] = k[i - 1][w];
			}
		}
		return k[n][W];
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter no. of items : ");
		int n = sc.nextInt();
		System.out.print("Enter weight of items : ");
		int wt[] = new int[n];
		for(int i = 0; i < n; i++)
			wt[i] = sc.nextInt();
		System.out.print("Enter item value : ");
		int val[] = new int[n];
		for(int i = 0; i < n; i++)
			val[i] = sc.nextInt();
		System.out.print("Enter maximum capacity of Knapsack : ");
		int W = sc.nextInt();
		System.out.println("Max Profit = " + knapsack(W, wt, val, n));
		sc.close();
	}

}
