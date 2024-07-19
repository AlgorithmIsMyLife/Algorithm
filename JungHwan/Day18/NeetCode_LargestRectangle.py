# 내 처음 답안
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        l = len(heights)
        maxA = 0
        stack = [] # [startIdx, height]
        for i in range(l):
            if len(stack) == 0:
                stack.append([i, heights[i]])
            else:
                #append higher height than before
                if stack[-1][1] < heights[i]:
                    stack.append([i, heights[i]])
                #elsewise pop all lower heights
                elif stack[-1][1] > heights[i]:
                    startIdx = 0
                    while len(stack) > 0 and stack[-1][1] > heights[i]:
                        index, height = stack.pop()
                        startIdx = index
                        maxA = max(maxA, (i - index) * height)
                    #now the top is lower than current height, so index starts from after it
                    stack.append([startIdx, heights[i]])
                else:
                    continue
            print(stack)
                    
        #stack is now in ascending order, with last index l
        for index, height in stack:
            maxA = max(maxA, (l - index) * height)
        return maxA

# 모범 답안
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        maxArea = 0
        stack = []  # pair: (index, height)

        for i, h in enumerate(heights):
            start = i
            while stack and stack[-1][1] > h:
                index, height = stack.pop()
                maxArea = max(maxArea, height * (i - index))
                start = index
            stack.append((start, h))

        for i, h in stack:
            maxArea = max(maxArea, h * (len(heights) - i))
        return maxArea

# 1. len(stack) > 0 판단은 그냥 stack으로 한다.
# 2. 큰 줄기로 보자. stack pop은 더 작은 높이가 등장했을 때이다. append는 생각해보면 높이가 같을 때 수행해도 무방하다. 