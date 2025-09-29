class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        #순서가 중요하지 않음
        numSet = set(nums)
        longest = 0

        for n in numSet:
            #수열의 시작점 찾기
            if (n-1) not in numSet:
                length = 1
                #set에서 search는 평균적으로 O(1)이다.
                while (n + length) in numSet:
                    length += 1
                longest = max(length, longest)
        return longest