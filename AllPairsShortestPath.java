package Unit_2;

import java.util.*;

public class AllPairsShortestPath {
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter number of vertices : ");
		int n= sc.nextInt();
		int cost[][] = new int[n][n];
		System.out.println("Enter the cost matrix : ");
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cost[i][j] = sc.nextInt();
		int A[][] = new int[n][n];
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				A[i][j] = cost[i][j];
			}
		}
		for(int k = 0; k < n; k++)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					A[i][j] = Math.min(A[i][j], A[i][k] + A[k][j]);
				}
			}
		}
		System.out.println("Shortest Path Matrix");
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				System.out.print(A[i][j] + " ");
			}
			System.out.println();
		}
		sc.close();
	}
}
