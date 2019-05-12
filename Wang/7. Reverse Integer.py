# -*-coding:utf8-*-
__author__ = 'Abbott'

"""
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
"""

class Solution:
  def reverse(self, x: int) -> int:
    if x > 2 ** 31 - 1 or x < -2 ** 31:
      return 0
    temp = str(x)
    if x == 0:
      return 0
    flag = False
    if x < 0:
      flag = True
      temp = temp[1:]
    temp = temp[::-1]
    if flag:
      temp = int("-" + temp)
    temp = int(temp)
    if temp > 2 ** 31 - 1 or temp < -2 ** 31:
      return 0
    return temp
