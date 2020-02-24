#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < n; ++i) {
      int startX = 0, startY = i;
      vector<int> temp;
      while (startX < m && startY < n) {
        temp.push_back(mat[startX++][startY++]);
      }
      sort(temp.begin(), temp.end());
      startX = 0, startY = i;
      for (auto item : temp) {
        mat[startX++][startY++] = item;
      }
    }

    for (int i = 1; i < m; ++i) {
      int startX = i, startY = 0;
      vector<int> temp;
      while (startX < m && startY < n) {
        temp.push_back(mat[startX++][startY++]);
      }
      sort(temp.begin(), temp.end());
      startX = i, startY = 0;
      for (auto item : temp) {
        mat[startX++][startY++] = item;
      }
    }

    return mat;
  }
};