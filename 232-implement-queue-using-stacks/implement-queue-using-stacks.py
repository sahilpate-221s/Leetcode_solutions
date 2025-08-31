class MyQueue:

    def __init__(self):
        self.st = []
        self.helper = []
        

    def push(self, x: int) -> None:
        self.st.append(x)

    def pop(self) -> int:
        self.peek()
        return self.helper.pop()
        

    def peek(self) -> int:
        if not self.helper:
            while self.st:
                self.helper.append(self.st.pop())

        return self.helper[-1]
        

    def empty(self) -> bool:
        return not self.st and not self.helper
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()