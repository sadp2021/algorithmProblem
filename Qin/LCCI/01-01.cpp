class Solution {
public:
    bool isUnique(string astr) {
        int bitDict = 0x0;
        for(int i = 0; i < astr.length(); i++){
            int pos = astr[i] - 'a';
            if((bitDict >> pos) & 0x1) // exist
                return false;
            bitDict |= (0x1 << pos);
        }
        return true;
    }
};
