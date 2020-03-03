# -*-coding:utf8-*-
__author__ = 'Abbott'
"""
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
"""


class Solution:
  def twoSum(self, nums, target):
    r = {}
    for x in range(len(nums)):
      temp = target - nums[x]
      if temp in r:
        return [r[temp], x]
      r[nums[x]] = x
