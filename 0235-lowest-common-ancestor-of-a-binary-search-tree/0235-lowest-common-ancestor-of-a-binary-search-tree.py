# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        pPath, qPath = [], []

        # find p
        node = root
        while True:
            pPath.append(node)
            if (node.val == p.val):
                break
            if (node.val < p.val):
                node = node.right
            else:
                node = node.left
        
        node = root
        while True:
            qPath.append(node)
            if (node.val == q.val):
                break
            if (node.val < q.val):
                node = node.right
            else:
                node = node.left
        
        pt = 0
        while (pt < len(pPath) and pt < len(qPath) and pPath[pt].val == qPath[pt].val):
            pt += 1
        return pPath[pt-1]
