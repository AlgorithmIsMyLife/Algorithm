class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        # print(tokens)
        if len(tokens) == 3:
            l, r, op = int(tokens[0]), int(tokens[1]), tokens[2]
            if op == "+":
                return l + r
            elif op == "-":
                return l - r
            elif op == "*":
                return l * r
            else:
                return l / r
        else:
            newTokens = [ str(Solution.evalRPN(Solution,tokens[:3])) ] +  tokens[3:]
            return Solution.evalRPN(Solution, newTokens)
        
class Solution:

    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for i in tokens:
            if i == "+":
                stack.append(str(int(stack.pop()) + int(stack.pop())))
            elif i == "-":
                a, b = int(stack.pop()), int(stack.pop())
                stack.append(str(b - a))
            elif i == "*":
                stack.append(str(int(stack.pop()) * int(stack.pop())))
            elif i == "/":
                a, b = float(stack.pop()), float(stack.pop())
                stack.append(str(int(b / a)))
            else:
                stack.append(i)
        return stack[0]
