class Solution {
	public int uniquePaths(int m, int n) {
		int[][] path = new int[n+1][m+1];
		for(int i = n-1; i >= 0; i--) {
			for(int j = m-1; j >= 0; j--) {
				if(i == n-1 && j == m-1)
					path[i][j] = 1;
				else
					path[i][j] = path[i+1][j] + path[i][j+1];
			}
		}
		return path[0][0];
	}
}

public class uniquePaths {
	public static void main(String[] args) {
		Solution so = new Solution();
		int m = 7;
		int n = 3;
		System.out.print(so.uniquePaths(m, n));
	}
}
