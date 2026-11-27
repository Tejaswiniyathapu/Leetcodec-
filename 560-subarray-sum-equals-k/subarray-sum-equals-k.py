class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        prefix_sum = 0
        hashmap = {0: 1}

        for num in nums:
            prefix_sum += num

            remaining = prefix_sum - k

            if remaining in hashmap:
                count += hashmap[remaining]

            hashmap[prefix_sum] = hashmap.get(prefix_sum, 0) + 1

        return count