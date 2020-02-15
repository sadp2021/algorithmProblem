# -*-coding:utf8-*-
__author__ = 'Abbott'

"""
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
"""


class Solution:
  def lengthOfLongestSubstring(self, s: str) -> int:
    hashMap = {}

    i, ans = 0, 0
    for j in range(len(s)):
      if s[j] in hashMap:
        i = max(i, hashMap[s[j]])
      ans = max(ans, j - i + 1)
      hashMap[s[j]] = j + 1
    return ans
