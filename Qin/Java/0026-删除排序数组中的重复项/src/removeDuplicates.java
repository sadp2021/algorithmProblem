class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        if(len == 0)
        	return 0;
        else if(len == 1)
        	return 1;
        int i = 0,j = 1;
        while(j != nums.length) {
        	if(nums[i] == nums[j])
        		j++;
        	else {
        		nums[i+1] = nums[j];
        		i++;
        		j++;
        	}
        }
        return i+1;
    }
}
public class removeDuplicates {
	public static void main(String[] args) {
		int[] a = {0,0};
		Solution so = new Solution();
		System.out.println(so.removeDuplicates(a));
		for(int k: a) {
			System.out.print(k+" ");
		}
	}
}
