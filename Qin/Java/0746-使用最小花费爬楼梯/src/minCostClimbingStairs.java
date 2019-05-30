class Solution {
	public int minCostClimbingStairs(int[] cost) {
		int res = 0;
		int len = cost.length;
		if(len < 2)
			return -1;
		int i = 2;
		int fd = cost[0];
		int sd = cost[1];
		res = Math.min(fd, sd);
		while(i <= len) {
			if(i != len) {
				res = Math.min(sd, fd)+cost[i];
				fd = sd;
				sd = res;
			} else {
				res = Math.min(sd, fd);
			}
			i++;
		}
		return res;
	}
}

public class minCostClimbingStairs {

}
