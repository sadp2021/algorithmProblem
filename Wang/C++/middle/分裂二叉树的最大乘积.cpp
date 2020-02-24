#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  long long sum = 0;
  long long maxVal = 0;

  void getSum(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    sum += root->val;
    getSum(root->left);
    getSum(root->right);
  }

  long long getMax(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    long long children = 0;
    children += (root->val + getMax(root->left) + getMax(root->right));

    maxVal = max(maxVal, (sum - children) * children);
    return children;
  }

 public:
  int maxProduct(TreeNode *root) {
    getSum(root);
    getMax(root);
    return maxVal % (long long)(1e9 + 7);
  }
};