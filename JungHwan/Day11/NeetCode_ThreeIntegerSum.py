class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        numSet = set(nums)
        answer = []
        first, firstVal = 0, nums[0]
        while True:
            print("first: ", first)
            start, end = first + 1, len(nums) - 1
            while start < end:
                print(str(start)+" "+str(end))
                if nums[first] + nums[start] + nums[end] > 0:
                    end -= 1
                elif nums[first] + nums[start] + nums[end] < 0:
                    start += 1
                else:
                    a = [nums[first],nums[start],nums[end]]
                    a.sort()
                    answer.append((a[0],a[1],a[2]))
                    end -= 1
                    start += 1

            #중복을 피하기 위해 이전보다 큰 first값 찾기
            while first < len(nums) - 3 and nums[first] == firstVal:
                first += 1
            if nums[first] == firstVal: break
            #사용하는 first값 저장
            firstVal = nums[first]
        print(answer)
        answer = set(answer)
        return list(map(lambda x:[x[0],x[1],x[2]],answer))
    

print(Solution.threeSum(Solution, [-1,0,1,2,-1,-4]))