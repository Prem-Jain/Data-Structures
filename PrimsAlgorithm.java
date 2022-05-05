package Unit_2;

import java.util.*;

public class PrimsAlgorithm {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int e, V, u = 0, v = 0, sum = 0, s = 0, minCost = Integer.MAX_VALUE;
		boolean flag = false;
		System.out.print("Enter the number of vertices : ");
		V = sc.nextInt();
		int cost[][] = new int[V][V];
		int sol[] = new int[V];
		System.out.print("Enter the cost matrix of graph : ");
		for(int i = 0; i < V; i++)
		{
			for(int j = 0; j < V; j++)
			{
				cost[i][j] = sc.nextInt();
				if(cost[i][j] != 0 && minCost > cost[i][j])
				{
					minCost = cost[i][j];
					s = i;
				}
			}
			sol[i] = 0;
		}
		sol[s] = 1;
		e = 1;
		while(e <= V - 1)
		{
			int min = 99;
			for(int i = 0; i < V; i++)
			{
				for(int j = 0; j < V; j++)
				{
					if(sol[i] == 1 && sol[j] == 0)
					{
						if(i != j && min > cost[i][j] && cost[i][j] != 0)
						{
							min = cost[i][j];
							u = i;
							v = j;
						}
					}
				}
				
			}
			sol[v] = 1;
			sum += min;
			e++;
			System.out.println(u + " - " + v + " -> " + min);
		}
		for(int i = 0; i < V; i++)
			if(sol[i] == 0)
				flag = true;
		if(flag)
			System.out.println("No spanning tree");
		else
			System.out.println("The cost of minimum spanning tree is "+sum);
		sc.close();
	}
}
