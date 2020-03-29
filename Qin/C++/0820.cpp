#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        map<string, int> T;
        for(string s: words){
            if(T.size() == 0) T[s] = 0;
            else {
                bool findable = false;
                for(auto i = T.begin(); i != T.end(); i++){
                    if(i->first.find(s) != string::npos){
                        findable = true;
                        i->second++;
                    }
                }
                if(!findable) T[s] = 0;
            }
        }

        int len = 0;
        for(auto i = T.begin(); i != T.end(); i++){
            len += i->first.length() + 1;
        }
        return  len;
    }
};