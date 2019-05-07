import java.util.*;

class ListNode {
	int val;
	ListNode next = null;
	ListNode(){};
	ListNode(int x) {
		val = x;
	}
}

public class Solution {
	public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		int C = (l1.val + l2.val) / 10;
		int T = (l1.val + l2.val) % 10;
		ListNode addHead = new ListNode(T);
		l1 = l1.next;
		l2 = l2.next;
		ListNode Head = addHead;
		while (l1 != null && l2 != null) {
			T = (l1.val + l2.val + C) % 10;
			C = (l1.val + l2.val) / 10;
			addHead.next = new ListNode(T);
			addHead = addHead.next;
			l1 = l1.next;
			l2 = l2.next;
		}
		if (l1 == null) {
			while (l2 != null) {
				T = (C + l2.val) % 10;
				C = l2.val / 10;
				addHead.next = new ListNode(T);
				addHead = addHead.next;
				l2 = l2.next;
			}
		} else if (l2 == null) {
			while (l1 != null) {
				T = (C + l1.val) % 10;
				C = l1.val / 10;
				addHead.next = new ListNode(T);
				addHead = addHead.next;
				l1 = l1.next;
			}
		}
		if(C != 0) {
			addHead.next = new ListNode(C);
			addHead = addHead.next;
		}
		return Head;
	}

	public static void input(ListNode l, int size, Scanner scan) {
		for(int i = 0; i < size; i++) {				
			l.val = scan.nextInt();
			l.next = new ListNode();
			l = l.next;
		}
	}
	
	public static void output(ListNode l) {
		while(l != null) {
			System.out.print(l.val);
		}
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		ListNode l1 = new ListNode();
		ListNode l2 = new ListNode();
		input(l1,4,scan);
		input(l2,4,scan);
		scan.close();
		ListNode l3 = addTwoNumbers(l1,l2);
		output(l3);
	}
}
