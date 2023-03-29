class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1:
            return len(s)

        substr = ""
        curstr = ""

        for c in s:
            print(curstr, c)
            if c in curstr:
                curstr = curstr[curstr.find(c) + 1:] + c
            else:
                curstr += c
            if len(curstr) > len(substr):
                substr = curstr
        return len(substr)