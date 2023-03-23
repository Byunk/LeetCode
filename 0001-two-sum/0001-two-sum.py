class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            l = nums[i]
            for j in range(i+1, len(nums)):
                r = nums[j]
                if (l + r == target):
                    return [i, j]
        