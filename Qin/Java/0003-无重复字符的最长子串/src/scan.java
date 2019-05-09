import java.util.*;

class Solution {
	public int lengthOfLongestSubstring(String s) {
		int j = 0, maxlen = 0;
		Deque<Character> res = new LinkedList<Character>();
		for (int i = 0; i < s.length(); i++) {
			char ch = s.charAt(i);
			if(res.contains(ch)) {
				char t;
				do {
					t = res.removeFirst();
					j--;
				} while(t != ch);
				res.addLast(ch);
				j++;
			} else {
				res.addLast(ch);
				j++;
			}
			maxlen = Math.max(maxlen, j);
		}
		return maxlen;
	}
}

public class scan {
	public static void main(String[] args) {
		String s = "asdaf";
		Solution so = new Solution();
		System.out.println(so.lengthOfLongestSubstring(s));
	}
}
