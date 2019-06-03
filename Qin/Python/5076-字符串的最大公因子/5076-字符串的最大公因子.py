class Solution:


    def gcdOfStrings(str1: str, str2: str) -> str:
        s1, s1 = "", ""
        res = ''
        if len(str1) < len(str2):
            s1 = str2
            s2 = str1
        else:
            s1 = str1
            s2 = str2
        len1 = len(s1)
        len2 = len(s2)
        for i in range(len2, 0, -1):
            flag = True
            if len1 % i == 0 and len2 % i == 0:
                res = s1[:i]
                start = 0
                end = i
                while end <= len1 and flag:
                    t1 = s1[start:end]
                    if s1[start:end] != res:
                        flag = False
                    else:
                        start += i
                        end += i
                start = 0
                end = i
                while end <= len2 and flag:
                    t2 = s2[start:end]
                    if s2[start:end] != res:
                        flag = False
                    else:
                        start += i
                        end += i
                if flag:
                    return res
        return ""


def main():
    str1 = 'ABABAB'
    str2 = 'ABAB'
    res = gcdOfStrings(str1, str2)
    print(res)


if __name__ == "__main__":
    main()
