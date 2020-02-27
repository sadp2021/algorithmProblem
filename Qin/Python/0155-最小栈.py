class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.eleStack = []
        self.minStack = [0]
        

    def push(self, x: int) -> None:
        self.eleStack.append(x)
        if x < self.eleStack[self.minStack[-1]-1]:
            self.eleStack.append(len(self.eleStack))
        
        self.print()

    def pop(self) -> None:
        if len(self.eleStack) - 1 == self.minStack[-1]:
            self.minStack.pop()
        self.eleStack.pop()

    def top(self) -> int:
        pass

    def getMin(self) -> int:
        pass
    
    def pushArr(self, a:list) -> None:
        for i in a:
            self.push(i)

    def print(self):
        print('eleStack', self.eleStack)
        print('minStack', self.minStack)


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

def main():
    ms = MinStack()
    ms.pushArr([3,4,5,6,7,4,1,2])
    
if __name__ == '__main__':
    main()
