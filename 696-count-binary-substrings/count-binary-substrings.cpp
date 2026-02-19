class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0;
        int consecutiveCount = 1;
        int lastConsecutiveCount = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]) {
                lastConsecutiveCount = consecutiveCount;
                consecutiveCount = 1;
                count++;
            } else {
                consecutiveCount++;
                if (consecutiveCount <= lastConsecutiveCount)
                    count++;
            }
        }
        return count;
    }
};
