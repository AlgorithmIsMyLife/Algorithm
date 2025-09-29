class Solution:
    def trap(self, height: List[int]) -> int:
        num = len(height)
        h, water = 0, 0
        while True:
            h += 1
            start = -1
            print(f"h: {h}")
            for i in range(num):
                #벽을 만났을 때
                if height[i] >= h:
                    #처음 마주하는 벽
                    if start == -1:
                        start = i
                    #start 다음 만난 벽
                    else:
                        water += (i - start - 1)
                        start = i 
            if start == -1:
                break
        return water

