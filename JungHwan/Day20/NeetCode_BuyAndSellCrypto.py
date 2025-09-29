class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxP = 0
        l, r = 0, 1
        while r < len(prices):
            p = prices[r] - prices[l]
            if p > 0:
                maxP = max(maxP, p)
            else:
                l = r
            r += 1
        return maxP