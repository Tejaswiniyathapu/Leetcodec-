class Solution {
public:
    string makeLargestSpecial(string s) {
          vector<string> parts;
        int balance = 0, start = 0;

        // Step 1: Split into primitive special substrings
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') balance++;
            else balance--;

            if (balance == 0) {
                // Step 2: Recursively process inner part
                string inner = s.substr(start + 1, i - start - 1);
                parts.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        // Step 3: Sort in descending order
        sort(parts.begin(), parts.end(), greater<string>());

        // Step 4: Concatenate
        string result;
        for (auto &p : parts) result += p;

        return result;
    }
};