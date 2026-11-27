class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        seen={}
        for i in range(len(nums)):
            needed= target - nums[i]

            if needed in seen:
                return[seen[needed], i] 

            seen[nums[i]]=i

        