# -*-coding:utf8-*-
__author__ = 'Abbott'

"""
给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。
"""


class Solution:
  def isMatch(self, s: str, p: str) -> bool:
    import re
    return re.match('^' + p + '$', s) != None
