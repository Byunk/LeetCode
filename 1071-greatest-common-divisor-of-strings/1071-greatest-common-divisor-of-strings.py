import math

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        # get a gcd of lengths of strings
        m = len(str1)
        n = len(str2)
        gcd = math.gcd(m, n)
        
        prestr1 = str1[:gcd]
        prestr2 = str2[:gcd]
        if prestr1 == prestr2:
            if prestr1 * (m//gcd) == str1 and prestr2 * (n//gcd) == str2:
                return prestr1
        return ""