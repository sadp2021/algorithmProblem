def max_sub_array(nums: list) -> int:
    res = -9999999999
    s = nums[0]
    for i in range(1, len(nums)):
        s = max(s + nums[i], nums[i])
        res = max(s, res)
    return res


def main():
    li = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print(max_sub_array(li))


if __name__ == "__main__":
    main()
