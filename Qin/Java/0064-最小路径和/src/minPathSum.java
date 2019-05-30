class Solution {
	public int minPathSum(int[][] grid) {
		int n = grid.length;
		int m = grid[0].length;
		int[][] path = new int[n][m];
		for(int i = n-1; i >= 0; i--) {
			for(int j = m-1; j >= 0; j--) {
				if(i == n-1 && j == m-1)
					path[i][j] = grid[i][j];
				else {
					if(i == n - 1)
						path[i][j] = path[i][j+1] + grid[i][j];
					else if(j == m - 1)
						path[i][j] = path[i+1][j] + grid[i][j];
					else
						path[i][j] = Math.min(path[i+1][j], path[i][j+1]) + grid[i][j];
				}
			}
		}
		return path[0][0];
	}
}

public class minPathSum {
	public static int[][] getarr(int m, int n) {
		int[][] arr = new int[m][n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = (int) (Math.random() * 7);
			}
		}
		return arr;
	}

	public static void printarr(int[][] arr) {
		System.out.print('[');
		for (int i = 0; i < arr.length; i++) {
			System.out.print('[');
			for (int j = 0; j < arr[0].length; j++) {
				if (j == arr[0].length - 1)
					System.out.print(arr[i][j]);
				else
					System.out.print(arr[i][j] + ",");
			}
			System.out.print(']');
			if (i != arr.length - 1)
				System.out.print(',');
		}
		System.out.print(']');
	}
	
	public static void main(String[] args) {
		printarr(getarr(4,7));
	}
}
