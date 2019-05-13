import java.util.*;

class Solution {

	public boolean isValid(String s) {
		Stack<Character> stack = new Stack<Character>();
		for (int i = 0; i < s.length(); i++) {
			char ch = s.charAt(i);
			if(ch == '('|| ch == '['||ch == '{') {
				stack.push(ch);
			} else {
				if(stack.isEmpty()) return false;
				char t = stack.pop();
				if(t == '(' && ch != ')') return false;
				if(t == '[' && ch != ']') return false;
				if(t == '{' && ch != '}') return false;
			}
		}
		if (stack.isEmpty())
			return true;
		else
			return false;
	}
}

public class Valid {
	public static void main(String[] args) {
		Solution so = new Solution();
		String s = "([)]";
		System.out.println(so.isValid(s));
	}
}
