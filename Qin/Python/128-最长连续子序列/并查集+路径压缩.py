class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        snum = set(nums)
        res = 0
        for num in snum:
            if num - 1 not in snum:
                curr_num = num
                curr_len = 1
                while curr_num + 1 in snum:
                    curr_num += 1
                    curr_len += 1
                res = max(res, curr_len)
        return res
                
                
