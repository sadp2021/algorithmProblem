import java.util.*;

class Solution {
	public String longestPalindrome(String s) {
		int len = s.length();
		int maxlen = 0;
		char[] chs = s.toCharArray();
		boolean[][] dp = new boolean[len][len];
		for (int i = 0; i < len; i++) {
			for (int j = 0; i + j < len; j++) {
				// dp[j][i] means s[j:i+1]
				int l = j;
				int r = i + j;
				if (i == 0)
					dp[l][r] = true;
				else if (i == 1) {
					if (chs[l] == chs[r])
						dp[l][r] = true;
					else
						dp[l][r] = false;
				} else {
					if (dp[l + 1][r - 1] == true && chs[l] == chs[r])
						dp[l][r] = true;
					else
						dp[l][r] = false;
				}

				if (dp[l][r] == true && r - l + 1 > maxlen)
					maxlen = r - l + 1;
			}
		}
		for (int i = 0; i < len; i++) {
			for (int j = 0; j + i < len; j++) {
				if (dp[j][i+j] == true && i + 1 == maxlen)
					return String.valueOf(Arrays.copyOfRange(chs, j, i+j+1));
			}
		}
		return "No";
	}
}

public class LongestPalindrome {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.nextLine();
		Solution so = new Solution();
		System.out.println(so.longestPalindrome(s));
	}
}
