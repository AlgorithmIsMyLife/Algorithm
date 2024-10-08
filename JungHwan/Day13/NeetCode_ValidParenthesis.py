class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for i in range(len(s)):
            if s[i] == "[" or s[i] == "(" or s[i] == "{":
                stack.append(s[i])
            elif s[i] == "]" and len(stack) > 0 and stack.pop() == "[":
                continue
            elif s[i] == ")" and len(stack) > 0 and stack.pop() == "(":
                continue
            elif s[i] == "}" and len(stack) > 0 and stack.pop() == "{":
                continue
            else: 
                return False
        if len(stack):
            return False
        return True