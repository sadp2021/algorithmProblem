import java.util.*;

class ListNode {
	int val;
	ListNode next = null;

	ListNode(int x) {
		val = x;
	}
}

public class Solution {
	public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		int T = (l1.val + l2.val) % 10;
		int C = (int) ((l1.val + l2.val) / 10);
		ListNode addHead = new ListNode(T);
		ListNode Head = addHead;
		l1 = l1.next;
		l2 = l2.next;
		while (l1 != null && l2 != null) {
			T = (l1.val + l2.val + C) % 10;
			C = (int) ((l1.val + l2.val + C) / 10);
			addHead.next = new ListNode(T);
			addHead = addHead.next;
			l1 = l1.next;
			l2 = l2.next;
		}
		if (l1 == null) {
			while (l2 != null) {
				T = (C + l2.val) % 10;
				C = (int) ((C + l2.val) / 10);
				addHead.next = new ListNode(T);
				addHead = addHead.next;
				l2 = l2.next;
			}
		} else {
			while (l1 != null) {
				T = (C + l1.val) % 10;
				C = (int) ((C + l1.val) / 10);
				addHead.next = new ListNode(T);
				addHead = addHead.next;
				l1 = l1.next;
			}
		}
		if (C != 0) {
			addHead.next = new ListNode(C);
		}
		return Head;
	}

	public static ListNode input(ListNode l, int size, Scanner scan) {
		ListNode Head = l;
		for (int i = 0; i < size; i++) {
			l.val = scan.nextInt();
			if (i != size - 1)
				l.next = new ListNode(-1);
			l = l.next;
		}
		return Head;
	}

	public static ListNode output(ListNode l) {
		ListNode Head = l;
		while (l != null) {
			System.out.print(l.val);
			l = l.next;
		}
		return Head;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		ListNode l1 = new ListNode(-1);
		ListNode l2 = new ListNode(-1);
		int n = scan.nextInt();
		int m = scan.nextInt();
		l1 = input(l1, n, scan);
		l2 = input(l2, m, scan);
		scan.close();
		ListNode l3 = addTwoNumbers(l1, l2);
		output(l3);
	}
}
