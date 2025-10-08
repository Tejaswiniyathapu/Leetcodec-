class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> repeated;
        vector<string> result;
        
        int n = s.size();
        if (n < 10) return result;

        for (int i = 0; i <= n - 10; i++) {
            string sub = s.substr(i, 10);
            if (seen.count(sub)) {
                repeated.insert(sub);
            } else {
                seen.insert(sub);
            }
        }
        
        for (auto &seq : repeated) {
            result.push_back(seq);
        }
        return result;
    }
};
