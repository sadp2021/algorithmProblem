class Solution {
	public int findFirst(String str) {
		char[] chs = str.toCharArray();
		boolean flag = true;
		for (int i = 0; i < chs.length; i++) {
			if (chs[i] == ' ' && flag)
				continue;
			else if ((chs[i] == '-' || chs[i] == '+') && flag) {
				flag = false;
				continue;
			} else {
				if (chs[i] >= '0' && chs[i] <= '9')
					return i;
				else
					return -1;
			}
		}
		return -1;
	}

	public String parse2num(char[] ch, int pos) {
		String num = "";
		for (int i = pos; i < ch.length; i++) {
			if (ch[i] >= '0' && ch[i] <= '9')
				num += ch[i];
			else
				break;
		}
		return num;
	}

	public int myAtoi(String str) {
		int position = findFirst(str);
		if (position == -1)
			return 0;
		char[] ch = str.toCharArray();
		boolean positive = true;
		if (position > 0 && ch[position - 1] == '-')
			positive = false;
		String num = parse2num(ch, position);
		int res = 0;
		try {
			res = Integer.parseInt(num);
			return positive ? res : -res;
		} catch (Exception e) {
			return positive ? 2147483647 : -2147483648;
		}
	}
}

public class myAtoi {
	public static void main(String[] args) {
		Solution so = new Solution();
		System.out.print(so.myAtoi("+1"));
	}
}
