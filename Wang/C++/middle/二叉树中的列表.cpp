#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  bool findRes(ListNode *current, TreeNode *root) {
    if (current == NULL) {
      return true;
    }
    if (root == NULL) {
      return false;
    }
    if (root->val != current->val) return false;

    return findRes(current->next, root->left) ||
           findRes(current->next, root->right);
  }

 public:
  bool isSubPath(ListNode *head, TreeNode *root) {
    if (root == NULL) return false;
    return findRes(head, root) || isSubPath(head, root->left) ||
           isSubPath(head, root->right);
  }
};