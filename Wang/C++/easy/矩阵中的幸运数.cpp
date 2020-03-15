#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    unordered_set<int> row, col;

    for (int i = 0; i < matrix.size(); ++i) {
      int min = matrix[i][0];
      for (int j = 1; j < matrix[0].size(); ++j) {
        if (matrix[i][j] < min) {
          min = matrix[i][j];
        }
      }
      row.insert(min);
    }
    for (int i = 0; i < matrix[0].size(); ++i) {
      int max = matrix[0][i];
      for (int j = 1; j < matrix.size(); ++j) {
        if (matrix[j][i] > max) {
          max = matrix[j][i];
        }
      }
      col.insert(max);
    }

    vector<int> res;
    for (auto& item : row) {
      if (col.find(item) != col.end()) {
        res.push_back(item);
      }
    }

    return res;
  }
};