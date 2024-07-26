class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        l, r = 0, 0
        cnt, window = {}, {}
        for i in s1:
            Solution.addDict(cnt, i)
        print("cnt:",cnt)

        while r < len(s2):
            print("l,r:",l,r)
            Solution.addDict(window, s2[r])
            if r >= len(s1):
                Solution.removeDict(window, s2[l])
                l += 1
            r += 1
            print("window:",window)
            if cnt == window:
                return True
        return False

    def addDict(d: dict, s: str):
        if s in d:
            d[s] += 1
        else:
            d[s] = 1
    
    def removeDict(d: dict, s: str):
        if d[s] == 1:
            del d[s]
        else:
            d[s] -= 1