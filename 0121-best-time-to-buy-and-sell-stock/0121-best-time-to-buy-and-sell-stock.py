class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_profit, min_buy = 0, 10000
        for price in prices:
            min_buy = min(price, min_buy)
            max_profit = max(price - min_buy, max_profit)
        return max_profit