class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        dic = {}
        for c in s:
            if c in dic:
               dic[c] += 1
            else:
                dic[c] = 1
        for c in t:
            if c in dic:
                dic[c] -= 1
            else:
                return False
        for n in dic.values():
            if n != 0:
                return False
        return True