class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       set<int> s(nums1.begin(), nums1.end());
    vector<int> result;

    for (int x : nums2)
        if (s.count(x)) { result.push_back(x); s.erase(x); }

    return result;


    }
};