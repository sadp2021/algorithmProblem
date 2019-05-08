import java.util.*;

class Solution {
	public int lengthOfLongestSubstring(String s) {
		int j = 0, maxlen = 0;
		String res = "";
//		String r = "";
		for (int i = 0; i < s.length(); i++) {
			int index = res.indexOf(s.charAt(i));
			if (index != -1) {
				if (j > maxlen) {
					maxlen = j;
//					r = res;
				}
				i -= j - index;
				j = 0;
				res = "";
				continue;
			} else {
				res += s.charAt(i);
				j++;
			}
		}
//		System.out.println(r);
		return maxlen == 0 ? j : maxlen;
	}
}

public class scan {
	public static void main(String[] args) {
		String s = "aab";
		Solution so = new Solution();
		System.out.println(so.lengthOfLongestSubstring(s));
	}
}
