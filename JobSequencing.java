package Unit_1;

import java.util.*;

class Job
{
	String id;
	int profit, deadline;
	Job(String i, int p, int dl)
	{
		id = i;
		profit = p;
		deadline = dl;
	}
}

public class JobSequencing {
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		String id;
		int dl, p, n, profit = 0;
		System.out.print("Enter the number of jobS : ");
		n = sc.nextInt();
		int max = Integer.MIN_VALUE;
		ArrayList<Job> a = new ArrayList<>();
		for(int i = 0; i < n; i++)
		{
			System.out.print("Enter id, deadline and profit :");
			id = sc.next();
			dl = sc.nextInt();
			p = sc.nextInt();
			max = Math.max(max, dl);
			a.add(new Job(id, p, dl));
		}
		Collections.sort(a, (n1, n2) -> n2.profit - n1.profit);
		boolean result[] = new boolean[max];
		String job[] = new String[max];
		for(int i = 0; i < n; i++)
		{
			for(int j = Math.min(max - 1, (a.get(i).deadline - 1)); j >= 0; j--)
			{
				if(result[j] == false)
				{
					result[j] = true;
					job[j] = a.get(i).id;
					profit += a.get(i).profit;
					break;
				}
			}
		}
		System.out.print("Job sequencing result : ");
		for(String s : job)
			System.out.print(s + " ");
		System.out.println("\nProfit earned : " + profit);
		sc.close();
	}
}
