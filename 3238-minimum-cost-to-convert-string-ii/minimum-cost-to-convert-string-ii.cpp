class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
    int n = source.length();
        unordered_map<string, int> strToId;
        int idCount = 0;

        for (const string& s : original) if (!strToId.count(s)) strToId[s] = idCount++;
        for (const string& s : changed) if (!strToId.count(s)) strToId[s] = idCount++;

        const long long INF = 1e16;
        vector<vector<long long>> dist(idCount, vector<long long>(idCount, INF));
        for (int i = 0; i < idCount; i++) dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = strToId[original[i]], v = strToId[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < idCount; k++) {
            for (int i = 0; i < idCount; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < idCount; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        vector<int> validLengths;
        for (auto const& [str, id] : strToId) {
            validLengths.push_back(str.length());
        }
        sort(validLengths.begin(), validLengths.end());
        validLengths.erase(unique(validLengths.begin(), validLengths.end()), validLengths.end());

        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            if (source[i] == target[i]) dp[i + 1] = min(dp[i + 1], dp[i]);

            for (int len : validLengths) {
                if (i + len <= n) {
                    string subS = source.substr(i, len);
                    string subT = target.substr(i, len);
                    
                    if (strToId.count(subS) && strToId.count(subT)) {
                        int u = strToId[subS], v = strToId[subT];
                        if (dist[u][v] < INF) {
                            dp[i + len] = min(dp[i + len], dp[i] + dist[u][v]);
                        }
                    }
                }
            }
        }

        return dp[n] >= INF ? -1 : dp[n];    
    }
};