class Solution:
    def longestPalindrome(self, s: str) -> int:
        letters = {}
        for c in s:
            if c in letters:
                letters[c] += 1
            else:
                letters[c] = 1

        keys = sorted(letters.keys(), reverse=True)

        out = 0
        existOdd = False
        for key in keys:
            if letters[key] % 2 != 0:
                if not existOdd:
                    out += letters[key]
                    existOdd = True
                else:
                    out += letters[key] - 1
            else:
                out += letters[key]
        if out == 0:
            return 1
        return out

