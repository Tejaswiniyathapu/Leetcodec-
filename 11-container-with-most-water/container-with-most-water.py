class Solution:
    def maxArea(self, height: list[int]) -> int:
        i = 0
        j =len(height)-1
        max_water = 0
        while i<j:
            width= j-i
            min_height = min(height[i],height[j])
            area = width * min_height
            max_water = max(max_water ,area)
            if height[i] < height[j]:
                i+=1
            else:
                j-=1
        return max_water 
        