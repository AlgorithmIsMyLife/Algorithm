class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        for k in nums:
            if(nums.count(k) > 1): return True
        return False