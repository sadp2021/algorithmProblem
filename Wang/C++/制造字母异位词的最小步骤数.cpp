#include <string>

class Solution {
	public:
		int minSteps(string s, string t) {
			vector<int> count(26,0);
			
			for (int i = 0; i < s.size(); ++i) {
				count[s[i] - 'a']++;
				count[t[i] - 'a']--;
			}
			
			int steps = 0;
			for (int i = 0; i < 26; ++i) {
				if (count[i] > 0) {
					steps += count[i];
				}
			}
			
			return steps;
		}
};
