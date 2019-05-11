import random
import time


def extends_find(s: str, i: int, o: int) -> int:
    """
    :param s: String
    :param i: lowerbound
    :param o: upperbound
    :return: find a longest palindrome starting in the mid position
    """
    start, end = i, o
    while start >= 0 and end < len(s) and s[start] == s[end]:
        start -= 1
        end += 1
    return end - start - 1


def extends_mid(s: str) -> str:
    """
    :param s:Target String
    :return: the longest palindrome in <s>
    """
    start, end = 0, 0
    res = ""
    for i in range(len(s)):
        l1 = extends_find(s, i, i)
        l2 = extends_find(s, i, i + 1)
        l = max(l1, l2)
        if l > end - start + 1:
            start = i - int((l - 1) / 2)
            end = i + int(l / 2)
    return s[start:end + 1]


def longest_palindrome(s: str) -> str:
    """
    DP method
    :param s: Target String
    :return: longest palindrome
    """
    length = len(s)
    maxlen = 0
    dp = [([False] * length) for i in range(length)]
    for i in range(length):
        for j in range(length - i):
            l = j
            r = i + j
            if i == 0:
                dp[l][r] = True
            elif i == 1:
                if s[l] == s[r]:
                    dp[l][r] = True
                else:
                    dp[l][r] = False
            else:
                if dp[l + 1][r - 1] and s[l] == s[r]:
                    dp[l][r] = True
                else:
                    dp[l][r] = False

            if dp[l][r] and i + 1 > maxlen:
                maxlen = i + 1

    # 可能有多个最长子序列，这里取第一个
    for i in range(length):
        for j in range(length - i):
            if dp[j][i + j] and i + 1 == maxlen:
                return s[j:i + j + 1]


def get_random_array(size: int) -> str:
    rand = ""
    for i in range(size):
        rand += chr(random.randint(97, 122))
    return rand


def exe_time(s: str, times: int) -> float:
    """
    :param s: String
    :param times: execute times
    :return: last time
    """
    start = time.time()
    for i in range(times):
        # longest_palindrome(s)
        extends_mid(s)
    end = time.time()
    return end - start


def main():
    s = get_random_array(1000)
    print(s)
    print(longest_palindrome(s))
    print(extends_mid(s))
    print(exe_time(s, 100))


if __name__ == "__main__":
    main()
