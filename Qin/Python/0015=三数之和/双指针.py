def three_num(nums: list) -> list:
    length = len(nums)
    res = []
    if length < 3:
        return []
    sort_list = sorted(nums)
    if sort_list[length - 1] < 0:  # 最大的小于0
        return []
    if sort_list[0] > 0:  # 最小的大于0
        return []
    if sort_list[0] == 0 and sort_list[length - 1] == 0:  # 全0
        return [[0, 0, 0]]
    for pos in range(1, length - 1):
        if sort_list[pos] == sort_list[pos+1]:
            continue
        l, r = pos - 1, pos + 1
        while l >= 0 and r <= length - 1:
            tsum = sort_list[l] + sort_list[pos] + sort_list[r]
            if tsum == 0:
                res.append([sort_list[l], sort_list[pos], sort_list[r]])
                while r + 1 < length and sort_list[r+1] == sort_list[r]:
                    r += 1
                r += 1
            elif tsum > 0:
                while l - 1 >= 0 and sort_list[l - 1] == sort_list[l]:
                    l -= 1
                l -= 1
            else:
                while r + 1 < length and sort_list[r + 1] == sort_list[r]:
                    r += 1
                r += 1
    return res


def main():
    print()
    l = [-1,0,1,0,0,1,-2]
    sl = sorted(l)
    print(sl)
    print(three_num(l))


if __name__ == "__main__":
    main()
