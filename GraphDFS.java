package Unit_4;

import java.util.*;

public class GraphDFS {
	static int v;
	static LinkedList<Integer> adj[];
	@SuppressWarnings("unchecked")GraphDFS(int v)
	{
		this.v = v;
		adj = new LinkedList[v];
		for(int i = 0; i < v; i++)
			adj[i] = new LinkedList();
	}
	
	void addEdge(int v, int w)
	{
		adj[v].add(w);
	}
	
	void DFSUtil(int s, boolean visited[])
	{
		visited[s] = true;
		System.out.print(s + " ");
		Iterator<Integer> i = adj[s].listIterator();
		while(i.hasNext())
		{
			int n = i.next();
			if(!visited[n])
			{
				DFSUtil(n, visited);
			}
		}
	}
	
	void DFS(int s)
	{
		boolean visited[] = new boolean[v];
		DFSUtil(s, visited);
	}
	
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter no. of edges : ");
		int n = sc.nextInt();
		GraphDFS g = new GraphDFS(n);
		for(int i = 0; i < n; i++)
		{
			int x = sc.nextInt();
			int y = sc.nextInt();
			g.addEdge(x, y);
		}
		System.out.print("Enter Source Vertex : ");
		int s = sc.nextInt();
		System.out.print("The DFS Traversal is ");
		g.DFS(s);
		sc.close();
	}

}
