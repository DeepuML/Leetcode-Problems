# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root):
        diameter = 0
        if root == None : 
            return 0

        left_ht = self.solve(root.left)
        right_ht = self.solve(root.right)

        self.diameter = max(self.diameter , right_ht + left_ht)

        return 1 + max(left_ht, right_ht)
    

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.diameter = 0
        self.solve(root)
        return self.diameter