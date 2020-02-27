class Trie:
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = {'':{'sub':{},'word':False}}

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        i, length = 0, len(word)
        now = self.root['']
        while i < length:
            tmp = word[:i+1]
            if tmp not in now['sub']:
                now['sub'][tmp] = {'sub':{},'word':False} if not i == length-1 else {'sub':{},'word':True}
            elif i == length - 1:
                now['sub'][tmp]['word'] = True
            now = now['sub'][tmp]
            i += 1
        
    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        i, length = 0, len(word)
        now = self.root['']
        while i < length:
            tmp = word[:i+1]
            if tmp not in now['sub']:
                return False
            elif now['sub'][tmp]['word'] and i == length - 1:
                return True
            now = now['sub'][tmp]
            i += 1
        return False

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        i, length = 0, len(prefix)
        now = self.root['']
        while i < length:
            tmp = prefix[:i+1]
            if tmp not in now['sub']:
                return False
            elif i == length - 1:
                return True
            now = now['sub'][tmp]
            i += 1
        return False
        

def main():
    t = Trie()
    t.print()
    t.insert('apple')
    t.insert('app')
    t.insert('ape')
    print(t.startsWith('ap'))
    print(t.startsWith('aa'))
    print(t.startsWith('aapple'))
    print(t.startsWith('appl'))

if __name__ == '__main__':
    main()
