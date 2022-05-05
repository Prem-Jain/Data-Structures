package Unit_2;

import java.util.*;

public class Kruskal_Algo {
	int v;
	int parent[];
	int find(int i)
	{
		while(parent[i] != 0)
			i = parent[i];
		return i;
	}
	
	void union(int i, int j)
	{
		if(i < j)
			parent[i] = j;
		else
			parent[j] = i;
	}
	
	void solve(int g[][], int V)
	{
		int u = 0, v = 0, sum = 0, e = 1, min;
		while(e <= V - 1)
		{
			min = 99;
			for(int i = 0; i < V; i++)
			{
				for(int j = 0; j < V; j++)
				{
					if(i != j && min > g[i][j] && g[i][j] != 0)
					{
						min = g[i][j];
						u = i;
						v = j;
					}
				}
			}
			int x = find(u);
			int y = find(v);
			if(x != y)
			{
				union(x, y);
				System.out.println(u + " - " + v + " -> " + g[u][v]);
				sum += min;
				e++;
			}
			g[u][v] = g[v][u] = 99;
		}
		System.out.println("Cost of the spanning Tree = " + sum);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no of vertices : ");
		int v = sc.nextInt();
		int g[][] = new int[v][v];
		Kruskal_Algo KA = new Kruskal_Algo();
		KA.parent  = new int[v];
		System.out.print("Enter the Cost matrix : ");
		for(int i = 0; i < v; i++)
		{
			for(int j = 0; j < v; j++)
			{
				g[i][j] = sc.nextInt();
			}
		}
		KA.solve(g, v);
		sc.close();
	}

}
