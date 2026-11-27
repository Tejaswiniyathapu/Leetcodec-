class Solution:
    def fourSumCount(self, nums1: list[int], nums2: list[int], nums3: list[int], nums4: list[int]) -> int:
        hashmap={}
        for a in nums1:
            for b in nums2:
                total = a+b
                hashmap[total]=hashmap.get(total,0)+1
        count =0
        for c in nums3:
            for d in nums4:
                remaining = -(c+d)
                if remaining in hashmap:
                    count +=hashmap[remaining]
        return count 



        
        