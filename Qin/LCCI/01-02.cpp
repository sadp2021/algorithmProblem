class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        map<char, int> m1, m2;
        int len = s1.length();
        for(int i = 0; i < len; i++){
            if(m1.find(s1[i]) != m1.end()) m1[s1[i]]++;
            else m1[s1[i]] = 1;
            if(m2.find(s2[i]) != m2.end()) m2[s2[i]]++;
            else m2[s2[i]] = 1;
        }
        
        if(m1.size() != m2.size()) return false;

        for(auto iter = m1.begin(); iter != m1.end(); iter++){
            if(m2.find(iter->first) == m2.end()) return false;
            else if(m2[iter->first] != iter->second) return false;
        }

        return true;
    }

};
