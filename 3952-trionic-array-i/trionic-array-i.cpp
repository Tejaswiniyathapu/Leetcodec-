class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 1;

        // strictly increasing
        while (i < n && nums[i] > nums[i-1]) i++;
        if (i == 1) return false;   // no increasing

        // strictly decreasing
        int downStart = i;
        while (i < n && nums[i] < nums[i-1]) i++;
        if (i == downStart) return false;   // no decreasing

        // strictly increasing again
        int upStart = i;
        while (i < n && nums[i] > nums[i-1]) i++;
        if (i == upStart) return false;   // no second increasing

        return i == n;   // must consume full array
    }
};
