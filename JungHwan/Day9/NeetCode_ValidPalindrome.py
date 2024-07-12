class Solution:
    def isPalindrome(self, s: str) -> bool:
        start, end = 0, len(s) - 1
        while start < end:
            while start + 1 < len(s) and s[start].isalnum() == False:
                start += 1
            while end - 1 >= 0 and s[end].isalnum() == False:
                end -= 1
            print(str(start)+" , "+str(end))
            if s[start].isalnum() == True and s[end].isalnum() == True and s[start].lower() != s[end].lower():
                return False
            else:
                start += 1
                end -= 1
        return True


