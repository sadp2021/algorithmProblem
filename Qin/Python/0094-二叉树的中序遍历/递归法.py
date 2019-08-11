# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def midTravel(self, root: TreeNode, nodelist: list):
        if root.left is not None:
            self.midTravel(root.left, nodelist)
        nodelist.append(root.val)
        if root.right is not None:
            self.midTravel(root.right, nodelist)

    def inorderTraversal(self, root: TreeNode) -> List[int]:
        nodelist = []
        if root is not None:
            self.midTravel(root, nodelist)
        return nodelist
