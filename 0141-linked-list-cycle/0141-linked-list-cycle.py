# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        node = head
        while node != None:
            if (node.val > 100000):
                return True
            node.val += 200000
            node = node.next
        return False
