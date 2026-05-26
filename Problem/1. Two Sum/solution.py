class Solution(object):
    def twoSum(self, nums, target):
        index = {}
        for i in range(len(nums)):
            temp = target - nums[i]
            if temp in index:
                return (index[temp],i)
            index[nums[i]] = i 
