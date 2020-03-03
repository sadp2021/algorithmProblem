#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  string rankTeams(vector<string>& votes) {
    unordered_map<char, vector<int>> m;
    int total = votes.size(), team = votes[0].size();

    for (int i = 0; i < team; ++i) {
      m[votes[0][i]] = vector<int>(team, 0);
    }

    for (int i = 0; i < total; ++i) {
      for (int j = 0; j < team; ++j) {
        m[votes[i][j]][j]++;
      }
    }

    vector<pair<char, vector<int>>> temp(m.begin(), m.end());
    sort(
        temp.begin(), temp.end(),
        [](const pair<char, vector<int>>& x, const pair<char, vector<int>>& y) {
          for (int i = 0; i < x.second.size(); ++i) {
            if (x.second[i] == y.second[i]) {
              continue;
            }
            return x.second[i] > y.second[i];
          }
          return x.first < y.first;
        });
    string res;
    for (int i = 0; i < temp.size(); ++i) {
      res += temp[i].first;
    }
    return res;
  }
};