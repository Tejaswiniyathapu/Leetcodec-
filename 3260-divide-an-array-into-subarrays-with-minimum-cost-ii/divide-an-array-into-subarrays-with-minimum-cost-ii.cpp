class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
     int n = nums.size();
        int need = k - 1;

        multiset<int> small, large;
        long long sum = 0;

        auto add = [&](int x) {
            small.insert(x);
            sum += x;

            if (small.size() > need) {
                auto it = prev(small.end());   
                sum -= *it;
                large.insert(*it);
                small.erase(it);
            }
        };

        auto remove = [&](int x) {
            if (small.find(x) != small.end()) {
                small.erase(small.find(x));
                sum -= x;

                if (!large.empty()) {
                    auto it = large.begin();  
                    sum += *it;
                    small.insert(*it);
                    large.erase(it);
                }
            }
            else {
                large.erase(large.find(x));
            }
        };

        for (int i = 1; i <= dist + 1; i++)
            add(nums[i]);

        long long ans = nums[0] + sum;

        int left = 1;

        for (int right = dist + 2; right < n; right++) {
            add(nums[right]);
            remove(nums[left]);
            left++;

            ans = min(ans, nums[0] + sum);
        }

        return ans;   
    }
};