class Solution:
    def climbStairs(self, n: int) -> int:
        memo = []
        for i in range(n):
            if (i == 0):
                memo.append(1)
                continue
            elif i == 1:
                memo.append(2)
                continue
            
            memo.append(memo[-1] + memo[-2])
        return memo[-1]
