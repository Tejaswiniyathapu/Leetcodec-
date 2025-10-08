class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited, int n) {
        visited[node] = true;
        for (int j = 0; j < n; j++) {
            if (isConnected[node][j] && !visited[j]) {
                dfs(j, isConnected, visited, n);
            }
        }
    }
    public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited, n);
                provinces++;
            }
        }
         return provinces;
    }
};
