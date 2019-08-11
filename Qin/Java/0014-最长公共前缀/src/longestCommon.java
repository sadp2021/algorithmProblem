class Solution1 {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0)
            return "";
        else if(strs.length == 1)
            return strs[0];
        StringBuilder res = new StringBuilder();
        int miniLen = strs[0].length();
        for(String s: strs){
            if(s.length() < miniLen)
                miniLen = s.length();
        }

        int index = 0;
        char temp;
        boolean f = true;
        while(index < miniLen){
            temp = strs[0].charAt(index);
            f = true;
            for(String s: strs){
                if(s.charAt(index) != temp)
                    f = false;
            }
            if(f)
                res.append(temp);
            else break;
            index++;
        }

        return res.toString();
    }
}

public class longestCommon {
    public static void main(String[] args) {
        Solution1 so = new Solution1();
        String[] strs = {"2","2","22"};
        System.out.println(so.longestCommonPrefix(strs));
    }
}
