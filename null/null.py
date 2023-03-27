class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        s = str(x)
        ln = len(s)
        
        l, r = 0, ln - 1
        while l <= r:
            if (s[l] != s[r]):
                return False
            l += 1
            r -= 1
        return True