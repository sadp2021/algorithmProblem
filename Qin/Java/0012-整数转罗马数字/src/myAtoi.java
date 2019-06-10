class Solution {
    public String intToRoman(int num) {
        String[] roma = {"M", "D", "C", "L", "X", "V", "I"};
        int index = 0;
        int handle;
        int f = 10000;
        StringBuilder sb = new StringBuilder();
        while (f != 1) {
            handle = (num % f) / (f / 10);
            while (handle != 0) {
                if (handle == 9) {
                    sb.append(roma[index]);
                    sb.append(roma[index - 2]);
                    handle -= 9;
                } else if (handle >= 5) {
                    sb.append(roma[index-1]);
                    handle -= 5;
                } else if (handle == 4) {
                    sb.append(roma[index]);
                    sb.append(roma[index-1]);
                    handle -= 4;
                } else {
                    sb.append(roma[index]);
                    handle--;
                }
            }
            index += 2;
            f /= 10;
        }
        return sb.toString();
    }
}

public class myAtoi {
    public static void main(String[] args) {
        Solution so = new Solution();
        System.out.println(so.intToRoman(1592));
    }
}
