class Solution:
    def isValid(cnt: dict, k: int) -> bool:
        #find major alphabet
        ma = max(cnt, key = cnt.get)
        s = sum(cnt.values()) - cnt[ma]
        print("cnt:",cnt)
        print("s:", s)
        return s <= k

    def updateCnt(cnt: dict, a: str):
        if a in cnt:
            cnt[a] += 1
        else: 
            cnt[a] = 1
        return

    def characterReplacement(self, s: str, k: int) -> int:
        l, r, maxl  = 0, 0, 0
        cnt = {}
        while l < len(s) and r < len(s):
            Solution.updateCnt(cnt, s[r])
            if Solution.isValid(cnt, k):
                maxl = max(r - l + 1, maxl)
            else:
                l += 1
                r = l
                cnt = {s[l]: 1}
            r += 1
        return maxl

    