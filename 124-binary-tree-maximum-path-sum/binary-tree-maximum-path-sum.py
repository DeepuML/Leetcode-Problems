# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root):
        if root == None:
            return 0
        ls = self.solve(root.left)
        if ls < 0:
            ls=0
        rs = self.solve(root.right)
        if rs < 0 : 
            rs = 0
        self.maxi = max(self.maxi , ls+rs+root.val)

        return root.val + max(ls, rs)        

    def maxPathSum(self, root: Optional[TreeNode]) -> int:

        self.maxi = float("-inf")
        self.solve(root)
        return self.maxi
        

        