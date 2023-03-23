class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for c in s:
            if (c == ")"):
                if (len(stack) == 0 or stack[-1] != "("):
                    return False
                else:
                    stack.pop()
            elif (c == "]"):
                if (len(stack) == 0 or stack[-1] != "["):
                    return False
                else:
                    stack.pop()
            elif (c == "}"):
                if (len(stack) == 0 or stack[-1] != "{"):
                    return False
                else:
                    stack.pop()
            else:
                stack.append(c)
        if (len(stack) != 0):
            return False
        return True