class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        if (row == 0) return ans;
        int col = matrix[0].size();

        int count = 0;
        int total = row * col;

        int strow = 0;
        int stcol = 0;
        int endrow = row - 1;
        int endcol = col - 1;

        while (count < total) {
            for (int index = stcol; index <= endcol && count < total; index++) {
                ans.push_back(matrix[strow][index]);
                count++;
            }
            strow++;

            for (int index = strow; index <= endrow && count < total; index++) {
                ans.push_back(matrix[index][endcol]);
                count++;
            }
            endcol--;

            for (int index = endcol; index >= stcol && count < total; index--) {
                ans.push_back(matrix[endrow][index]);
                count++;
            }
            endrow--;

            for (int index = endrow; index >= strow && count < total; index--) {
                ans.push_back(matrix[index][stcol]);
                count++;
            }
            stcol++;
        }

        return ans;
    }
};
