# -*-coding:utf8-*-
__author__ = 'Abbott'


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
