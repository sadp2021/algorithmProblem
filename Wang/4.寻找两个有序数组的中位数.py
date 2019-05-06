# -*-coding:utf8-*-
__author__ = 'Abbott'

"""
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。
"""


class Solution:
  def findMedianSortedArrays(self, nums1: list, nums2: list):
    m, n = len(nums1), len(nums2)
    if m > n:
      nums1, nums2, m, n = nums2, nums1, n, m
    if n == 0:
      raise ValueError

    imin, imax, half_len = 0, m, (n + m + 1) / 2
    while imin <= imax:
      i = (imin + imax) / 2
      j = half_len - i
      if i < m and nums2[j - 1] > nums1[i]:
        imin = i + 1
      elif i > 0 and nums1[i - 1] > nums2[j]:
        imax = i - 1
      else:
        if i == 0:
          max_of_left = nums2[j - 1]
        elif j == 0:
          max_of_right = nums1[i - 1]
        else:
          max_of_left = max(nums1[i - 1], nums2[j - 1])

        if (m + n) % 2 == 1:
          return max_of_left

        if i == m:
          min_of_right = nums2[j]
        elif j == n:
          min_of_right = nums1[i]
        else:
          min_of_right = min(nums1[i], nums2[j])

        return (max_of_left + min_of_right) / 2.0
