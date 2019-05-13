# -*-coding:utf8-*-
__author__ = 'Abbott'

"""
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
"""


class Solution:
  def maxArea1(self, height: list) -> int:
    maxValue = 0
    for i in range(len(height)):
      for j in range(i + 1, len(height)):
        maxValue = max(maxValue, min(height[i], height[j]) * (j - i))
    return maxValue

  def maxArea(self, height: list) -> int:
    maxValue = 0
    i, j = 0, len(height) - 1
    while i != j:
      maxValue = max(maxValue, min(height[i], height[j]) * (j - i))
      if height[i] <= height[j]:
        i += 1
      else:
        j += 1
    return maxValue
