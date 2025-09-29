class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l, r = 0, 0
        maxl = 0
        while r < len(s):
            for i in range(l, r):
                if s[r] == s[i]: #found duplicate
                    l = r = i + 1
                    break
                #duplicate not found
            maxl = max(maxl, r - l + 1)
            r += 1
        return maxl