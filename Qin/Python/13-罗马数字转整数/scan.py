class Solution:
    def romanToInt(self, s: str) -> int:
        sum = 0
        value_d = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        class_d = {'I': 0, 'V': 1, 'X': 2, 'L': 3, 'C': 4, 'D': 5, 'M': 6}
        nowclass = 0
        sr = s[::-1]
        for ch in sr:
            csclass = class_d[ch]
            csvalue = value_d[ch]
            if nowclass <= csclass:
                sum += csvalue
                nowclass = csclass
            elif nowclass > csclass:
                sum -= csvalue
        return sum


def main():
    solution = Solution()
    print("main")
    print(solution.romanToInt("XIX"))


if __name__ == "__main__":
    main()
