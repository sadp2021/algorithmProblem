class Solution {
	public int removeElement(int[] nums, int val) {
		int len = nums.length;
		if (len == 0)
			return 0;
		int i = 0;
		int j = 0;
		while (j != len) {
			if (nums[j] == val)
				j++;
			else {
				nums[i] = nums[j];
				i++;
				j++;
			}
		}
		return i;
	}
}

public class removeElements {
	public static void main(String[] args) {
		Solution so = new Solution();
		int[] nums = {1,2,3,4,5,2,12,31,34,4,2,3,4,5,2,34,56,4};
		int len = so.removeElement(nums, 2);
		for(int i = 0; i < len; i++)
			System.out.print(nums[i]+" ");
	}
}
