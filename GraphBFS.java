package Unit_4;

import java.util.*;

public class GraphBFS {
	static int v;
	static LinkedList<Integer> adj[];
	@SuppressWarnings("unchecked")GraphBFS(int v)
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
	
	void BFS(int s)
	{
		boolean visited[] = new boolean[v];
		LinkedList<Integer> queue = new LinkedList<Integer>();
		visited[s] = true;
		queue.add(s);
		while(queue.size() != 0)
		{
			s = queue.poll();
			System.out.print(s + " ");
			Iterator<Integer> i = adj[s].listIterator();
			while(i.hasNext())
			{
				int n = i.next();
				if(!visited[n])
				{
					visited[n] = true;
					queue.add(n);
				}
			}
		}
	}
	
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter no. of edges : ");
		int n = sc.nextInt();
		GraphBFS g = new GraphBFS(n);
		for(int i = 0; i < n; i++)
		{
			int x = sc.nextInt();
			int y = sc.nextInt();
			g.addEdge(x, y);
		}
		System.out.print("Enter Source Vertex : ");
		int s = sc.nextInt();
		System.out.print("The BFS Traversal is ");
		g.BFS(s);
		sc.close();
	}

}
