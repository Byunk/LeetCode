class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        currMax = overallMax = nums[0]
        for i in range(1, len(nums)):
            currMax = max(currMax + nums[i], nums[i])
            overallMax = max(currMax, overallMax)

        return overallMax