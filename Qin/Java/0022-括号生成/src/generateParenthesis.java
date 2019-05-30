import java.util.*;

class Solution {
	public ArrayList<String> generateParenthesis(int n) {
		ArrayList<String> res = new ArrayList<String>();
		backtrack("", 0, 0, n, res);
		return res;
	}

	public void backtrack(String str, int rightAble, int left, int count, ArrayList<String> res) {
		if (str.length() == 2 * count) {
			res.add(str);
			return;
		}
		if (left < count)
			backtrack(str + "(", rightAble + 1, left + 1, count, res);
		if (rightAble > 0)
			backtrack(str + ")", rightAble - 1, left, count, res);
	}
}

public class generateParenthesis {
	public static void main(String[] args) {
		Solution so = new Solution();
		ArrayList<String> r = so.generateParenthesis(4);
		System.out.print(r.toString());
	}
}
