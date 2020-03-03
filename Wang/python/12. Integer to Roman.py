# -*-coding:utf8-*-
__author__ = 'Abbott'

"""
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
"""


class Solution:
  def intToRoman(self, num: int) -> str:
    d = {1000: 'M', 900: 'CM', 500: 'D', 400: 'CD', 100: 'C', 90: 'XC', 50: 'L', 40: 'XL', 10: 'X', 9: 'IX', 5: 'V',
         4: 'IV', 1: 'I'}
    res = ''
    for k, v in d.items():
      while num >= k:
        res += d[k]
        num -= k
    return res
