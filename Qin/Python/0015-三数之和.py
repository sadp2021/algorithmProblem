def main():
    def threeSum(nums: list) -> list:
        length = len(nums)
        if length < 3:
            return []
        res = {}
        nums.sort()
        for mid in range(1, length - 1):  # mid
            print(res)
            left,right = 0, length - 1
            while left < mid < right:
                tmp = nums[left]+nums[mid]+nums[right]
                if tmp < 0:
                    left += 1
                elif tmp > 0:
                    right -= 1
                else:
                    group = (nums[left],nums[mid],nums[right])
                    left += 1
                    right -= 1
                    if group not in res:
                        res[group] = 1
        return res

    threeSum([-1,0,1,2,-1,-4])

if __name__ == '__main__':
    main()
