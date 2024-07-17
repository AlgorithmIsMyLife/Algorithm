class Solution:
    def search(self, nums: List[int], target: int) -> int:
        start, end = 0, len(nums) - 1
        while start <= end:
            c = int(start + (end - start) / 2)
            if nums[c] < target:
                start = c + 1
            elif nums[c] > target:
                end = c - 1
            else: return c
        return -1 