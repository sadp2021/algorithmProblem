class Solution {
    public int climbStairs(int n) {
    	int a = 1;
    	int b = 2;
    	int count = 3;
        if(n == 1)
        	return a;
        else if(n == 2)
        	return b;
        else {
        	while(count <= n) {
        		switch(count%2) {
        		case 0:a += b;break;
        		case 1:b += a;break;
        		}
        		count++;
        	}
        }
        return Math.max(a, b);
    }
}
public class climbStairs {

}
