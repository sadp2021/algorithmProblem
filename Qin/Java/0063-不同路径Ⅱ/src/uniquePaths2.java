class Solution {
	public int uniquePathsWithObstacles(int[][] obstacleGrid) {
		int m = obstacleGrid.length; // row
		int n = obstacleGrid[0].length; // col
		int[][] path = new int[m + 1][n + 1];
		for (int i = m - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (i == m - 1 && j == n - 1)
					path[i][j] = 1;
				else if (obstacleGrid[i][j] == 1)
					continue;
				else {
					if (i + 1 < m && obstacleGrid[i + 1][j] != 1)
						path[i][j] += path[i + 1][j];
					if (j + 1 < n && obstacleGrid[i][j + 1] != 1)
						path[i][j] += path[i][j + 1];
				}
			}
		}
		return path[0][0];
	}
}

public class uniquePaths2 {
	public static int[][] getarr(int m, int n) {
		int[][] arr = new int[m][n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i % 2 == 0 && j % 2 == 1)
					arr[i][j] = (int) (Math.random() * 2);
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
		printarr(getarr(0, 0));
	}
}
