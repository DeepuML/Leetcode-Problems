# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def solve(self, root): 
        if root == None : 
            return 0

        left_ht = self.solve(root.left)
        right_ht = self.solve(root.right)

        return max(left_ht,right_ht) + 1

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.solve(root)

        