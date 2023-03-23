# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    ans = True
    
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None:
            return True

        self.isHeightBalanced(root)
        return self.ans
        
    def isHeightBalanced(self, node):
        if (node == None):
            return 0

        leftHeight = self.isHeightBalanced(node.left)
        rightHeight = self.isHeightBalanced(node.right)
        if (abs(leftHeight - rightHeight) > 1):
            self.ans = False
        return max(leftHeight, rightHeight) + 1

        