package Unit_2;

import java.util.*;

public class MultiStage {

	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			System.out.print("Enter number of vertices : ");
			int n= sc.nextInt();
			int cost[][] = new int[n][n];
			System.out.println("Enter the cost matrix : ");
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					cost[i][j] = sc.nextInt();
			int s[] = new int[n];
			int p[] = new int[n];
			int temp[] = new int[n];
			int i, j;
			for(i = 0; i < n; i++)
				s[i] = temp[i] = p[i] = 0;
			System.out.print("1. Forward Approach 2. Backward Approach\nSelect any one method : ");
			int option = sc.nextInt();
			switch(option)
			{
				case 1: 
					for(i = n - 2; i >= 0; i--)
					{
						boolean c = true;
						for(j = 0; j < n; j++)
						{
							if(cost[i][j] != 0)
							{
								if(c)
								{
									s[i] = s[j] + cost[i][j];
									p[i] = j;
									c = false;
								}
								else
								{
									temp[i] = s[j] + cost[i][j];
									if(temp[i] < s[i])
									{
										s[i] = s[j] + cost[i][j];
										p[i] = j;
									}
								}
							}
						}
					}
					System.out.print("Optimal path : ");
					i = p[0];
					System.out.print("0 --> " + i);
					while(i != n - 1)
					{
						i = p[i];
						System.out.print(" -- > " + i);
					}
					System.out.println("\nShortest Distance = " + s[0]);
					break;
				case 2:
					for(j = 0; j < n; j++)
					{
						boolean c = true;
						for(i = 0; i < n; i++)
						{
							if(cost[i][j] != 0)
							{
								if(c)
								{
									s[j] = s[i] + cost[i][j];
									p[j] = i;
									c = false; 
								}
								else
								{
									temp[j] = s[i] + cost[i][j];
									if(temp[j] < s[j])
									{
										s[j] = s[i] + cost[i][j];
										p[j] = i;
									}
								}
							}
						}
					}
					System.out.print("Optimal path : ");
					i = p[n - 1];
					System.out.print((n - 1) + " --> " + i);
					while(i != 0)
					{
						i = p[i];
						System.out.print(" -- > " + i);
					}
					System.out.println("\nDistance = " + s[n - 1]);
					break;
			}
			sc.close();
		}
	}

}
