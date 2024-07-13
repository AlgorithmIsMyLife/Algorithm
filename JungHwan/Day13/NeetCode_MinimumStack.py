class MinStack:

    def __init__(self):
        MinStack.stack = []

    def push(self, val: int) -> None:
        MinStack.stack.append(val)

    def pop(self) -> None:
        MinStack.stack.pop()

    def top(self) -> int:
        return MinStack.stack[len(MinStack.stack) - 1]

    def getMin(self) -> int:
        m = MinStack.stack[0]
        for i in MinStack.stack:
            if i < m:
                m = i
        return m
