class Solution:
    def maxArea(self, heights: List[int]) -> int:
        max, num = 0, len(heights)
        for i in range(num):
            for j in range(i+1, num):
                h = min(heights[i], heights[j])
                if max < (j - i) * h:
                    max = (j - i) * h
        return max