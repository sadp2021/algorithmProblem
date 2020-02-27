class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = {'':[{}, 0]}
        self.d = {}

    def insert(self, key: str, val: int) -> None:
        diff = 0
        flag = False
        if key in self.d:
            diff = val - self.d[key]
            flag = True
            self.d[key] = val
        else:
            self.d[key] = val
        print(flag)
        tmp = ''
        now = self.root[''][0]
        if not flag:
            for ch in key:
                tmp += ch
                if tmp in now:
                    now[tmp][1] += val
                else:
                    now[tmp] = [{}, val]
                now = now[tmp][0]
        else:
            for ch in key:
                tmp += ch
                now[tmp][1] += diff
                now = now[tmp][0]
        self.print()

    def sum(self, prefix: str) -> int:
        tmp = ''
        now = self.root[''][0]
        for ch in prefix:
            tmp += ch
            if tmp not in now:
                return 0
            elif tmp == prefix:
                return now[tmp][1]
            now = now[tmp][0]
        return 0
    
    def print(self):
        print(self.root)
        print(self.d)

# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
def main():
    mp = MapSum()
    mp.insert('aa',2)
    mp.insert('aa',3)

if __name__ == '__main__':
    main()
