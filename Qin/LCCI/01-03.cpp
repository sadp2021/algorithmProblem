class Solution {
public:
    string replaceSpaces(string S, int length) {
        int len = S.length();
        for(int i = len - 1; i >= len - length; i--) S[i] = S[i-len+length];
        int i = 0;
        for(int j = len - length; j < len; j++){
            if(S[j] != ' ') S[i++] = S[j];
            else {
                S[i++] = '%';
                S[i++] = '2';
                S[i++] = '0';
            }
        }
        S[i] = '\0';
        return S;
    }
};
