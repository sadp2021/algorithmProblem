import java.util.*;

class Solution {
	public ArrayList<String> generateParenthesis(int n) {
		ArrayList<String> res = new ArrayList<String>();
		backtrack("", 0, 0, n, res);
		return res;
	}

	public void backtrack(String str, int rightAble, int left, int count, ArrayList<String> res) {
		if (rightAble < 0 || left == count)
			return;
		backtrack(str + "(", rightAble + 1, left + 1, count, res);
		backtrack(str + ")", rightAble - 1, left, count, res);
		if (str.length() == 6) {
			res.add(str);
			return;
		}
	}
	
}

public class generateParenthesis {
	public static void main(String[] args) {
		Solution so = new Solution();
		ArrayList<String> r = so.generateParenthesis(3);
		System.out.print(r.toString());
	}
}
 