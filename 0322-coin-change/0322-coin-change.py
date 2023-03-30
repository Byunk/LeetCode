class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0

        self.res = 10001
        self.isPossible = False
        self.coins = sorted(coins, reverse=True)
        self.memo = [10001 for _ in range(amount + 1)]
        
        self.dfs(0, amount)
        if not self.isPossible:
            return -1

        return self.res

    def dfs(self, cnt, remain):
        if remain == 0 and cnt < self.res:
            self.isPossible = True
            self.res = cnt
            return

        for coin in self.coins:
            if remain - coin < 0 or self.memo[remain - coin] <= cnt + 1 or cnt + 1 >= self.res:
                continue
            self.memo[remain - coin] = cnt + 1
            self.dfs(cnt + 1, remain - coin)
        