# -*-coding:utf8-*-
__author__ = 'Abbott'

"""
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
"""


class Solution:
  def longestCommonPrefix(self, strs: list) -> str:
    if '' in strs or len(strs) == 0:
      return ''

    res = ''
    for index, item in enumerate(strs[0]):
      for j in range(1, len(strs)):
        if index >= len(strs[j]) or item != strs[j][index]:
          return res
      res += item

    return res
