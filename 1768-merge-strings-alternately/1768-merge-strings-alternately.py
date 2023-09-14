class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        pt1 = 0
        pt2 = 0

        ret = ""
        while pt1 < len(word1) or pt2 < len(word2):
            if pt1 == len(word1):
                ret += word2[pt2]
                pt2 += 1
            elif pt2 == len(word2):
                ret += word1[pt1]
                pt1 += 1
            else:
                ret += word1[pt1] + word2[pt2]
                pt1 += 1
                pt2 += 1
        return ret