class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        n = len(speed)
        ordered = []
        for i in range(n):
            ordered.append([position[i],speed[i]])
        ordered.sort(reverse=True, key = lambda x: x[0])
        print(ordered)
        
        stack = []
        for p, s in ordered:
            t = (target - p)/s
            stack.append(t)
            if len(stack) >= 2 and stack[-2] >= stack[-1]:
                stack.pop()
            print(stack)
        return len(stack)