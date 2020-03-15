#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  vector<int> vec;
  void dfs(TreeNode* root) {
    if (root == nullptr) {
      return;
    }
    dfs(root->left);
    vec.push_back(root->val);
    dfs(root->right);
  }
  TreeNode* construct(int L, int R) {
    if (L > R) {
      return nullptr;
    }
    int mid = (L + R) >> 1;
    auto ptr = new TreeNode(vec[mid]);
    ptr->right = construct(mid + 1, R);
    ptr->left = construct(L, mid - 1);
    return ptr;
  }

 public:
  TreeNode* balanceBST(TreeNode* root) {
    if (root == nullptr) {
      return nullptr;
    }
    dfs(root);
    return construct(0, vec.size() - 1);
  }
};