package Unit_4;

import java.util.*;

public class NQueenProblem {
	int count = 0;
	boolean isSafe(int board[][], int row, int col)
	{
		int i, j;
		for(i = 0; i < col; i++)
			if(board[row][i] == 1)
				return false;
		for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
			if(board[i][j] == 1)
				return false;
		for(i = row, j = col; j>= 0 && i < board.length; i++, j--)
			if(board[i][j] == 1)
				return false;
		return true;
	}
		
	void printSolution(int board[][])
    {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++)
                System.out.print(" " + board[i][j]
                                 + " ");
            System.out.println();
        }
    }
 
	boolean solveNQUtil(int board[][], int col)
    {
        if (col >= board.length)
            return true;
        for (int i = 0; i < board.length; i++)
        {
        	if (isSafe(board, i, col)) {
                board[i][col] = 1;
                if (solveNQUtil(board, col + 1) == true)
                    return true;
                board[i][col] = 0;
            }
        }
        return false;
    }
    boolean solveNQ()
    {
    	Scanner sc = new Scanner(System.in);
		System.out.println("Enter row n cols : ");
		int n = sc.nextInt();
		int board[][] = new int[n][n];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				board[i][j] = 0;
		sc.close();
        if (solveNQUtil(board, 0) == false) {
            System.out.print("Solution does not exist");
            return false;
        }
 
        printSolution(board);
        return true;
    }
	public static void main(String args[])
	{
		NQueenProblem Queen = new NQueenProblem();
		Queen.solveNQ();
	}
}
