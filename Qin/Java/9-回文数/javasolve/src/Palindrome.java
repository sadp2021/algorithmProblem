import java.util.*;

public class Palindrome {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int x = scan.nextInt();
		scan.close();
		System.out.print(isPalindrome(x));
	}
    public static boolean isPalindrome(int x) {
        String num = String.valueOf(x);
		StringBuilder t = new StringBuilder(num);
		String numreverse = t.reverse().toString();
		if(num.equals(numreverse)) return true;
		else return false;
    }
}
