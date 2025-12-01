class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         unordered_set<int> seen;
        seen.reserve(nums.size());     
        seen.max_load_factor(0.7);      

        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }

        return false;
    }
    
};