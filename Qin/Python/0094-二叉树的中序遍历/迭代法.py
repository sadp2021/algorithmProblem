# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def top(l :list) ->TreeNode:
        return l[len(l)-1]
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        stack = []
        res = []
        stack.append(root)
        while len(stack) is not 0:
            top = self.top(stack)
            while self.top(stack).left is not None:
                stack.append(self.top(stack).left)
            res.append(top.val)
            if top.right is not None:
                stack.append(top.right)
        return res
            
