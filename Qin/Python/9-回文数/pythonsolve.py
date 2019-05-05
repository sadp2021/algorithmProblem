class Solution:
    def isPalindrome(self, x: int) -> bool:
        s = str(x)
        if s == s[::-1]:
            return True
        else:
            return False


if __name__ == '__main__':
    s = Solution()
    x = 121
    print(s.isPalindrome(s))
