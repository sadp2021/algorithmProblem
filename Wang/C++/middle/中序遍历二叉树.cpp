#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  vector<int> temp;

  void middle(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    middle(root->left);
    temp.push_back(root->val);
    middle(root->right);
  }

 public:
  vector<int> inorderTraversal(TreeNode *root) {
    middle(root);
    return temp;
  }
};