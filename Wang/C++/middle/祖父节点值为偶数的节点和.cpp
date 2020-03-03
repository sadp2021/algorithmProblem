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
  int sum;
  void findAns(TreeNode *root) {
    if (root == NULL) {
      return;
    }
    if (root->val % 2 == 0) {
      if (root->left != NULL) {
        if (root->left->left != NULL) {
          sum += root->left->left->val;
        }
        if (root->left->right != NULL) {
          sum += root->left->right->val;
        }
      }
      if (root->right != NULL) {
        if (root->right->left != NULL) {
          sum += root->right->left->val;
        }
        if (root->right->right != NULL) {
          sum += root->right->right->val;
        }
      }
    }
    findAns(root->left);
    findAns(root->right);
  }

 public:
  int sumEvenGrandparent(TreeNode *root) {
    sum = 0;
    findAns(root);

    return sum;
  }
};