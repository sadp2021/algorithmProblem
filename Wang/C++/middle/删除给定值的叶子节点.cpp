#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  int gtarget;

  bool del(TreeNode* root) {
    if (root == NULL) {
      return false;
    }
    if (del(root->left)) {
      root->left = NULL;
    }
    if (del(root->right)) {
      root->right = NULL;
    }
    if (root->left == NULL && root->right == NULL && root->val == gtarget) {
      return true;
    }
    return false;
  }

 public:
  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    gtarget = target;
    if (del(root)) {
      root = NULL;
    }
    return root;
  }
};