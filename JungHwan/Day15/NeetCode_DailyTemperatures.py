class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        n = len(temperatures)
        stack = [] # [value, index]
        output = [0] * n
        for i in range(n):
            while len(stack) > 0 and stack[-1][0] < temperatures[i]:
                [value, index] = stack.pop()
                output[index] =  i - index
            stack.append([temperatures[i], i])
        return output
    
temperatures = [30,38,30,36,35,40,28]
print(Solution.dailyTemperatures(Solution, temperatures))