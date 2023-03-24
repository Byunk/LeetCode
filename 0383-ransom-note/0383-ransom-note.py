class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        dictionary = {}
        for c in magazine:
            if c in dictionary:
                dictionary[c] += 1
            else:
                dictionary[c] = 1
        
        for c in ransomNote:
            if c not in dictionary:
                return False
            else:
                dictionary[c] -= 1
                if dictionary[c] < 0:
                    return False
        return True