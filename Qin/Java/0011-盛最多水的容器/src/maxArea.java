class Solution {
	public int maxArea(int[] height) {
		int left = 0;
		int right = height.length - 1;
		int max = 0;
		int v = 0;
		boolean bigger = false;
		while (left != right) {
			if (height[right] > height[left]) {
				bigger = true;
				v = (right - left) * height[left];
			} else {
				bigger = false;
				v = (right - left) * height[right];
			}
				
			if (v > max)
				max = v;
			if (bigger)
				left++;
			else
				right--;
		}
		return max;
	}
}

public class maxArea {

}
