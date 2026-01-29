#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        const int ALPHABET = 26;
        const long long INF = 1e15;
        
        // Initialize distance matrix
        vector<vector<long long>> dist(ALPHABET, vector<long long>(ALPHABET, INF));
        for (int i = 0; i < ALPHABET; i++) dist[i][i] = 0;
        
        // Add given transformations
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        
        // Floyd-Warshall to compute all-pairs shortest paths
        for (int k = 0; k < ALPHABET; k++) {
            for (int i = 0; i < ALPHABET; i++) {
                for (int j = 0; j < ALPHABET; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // Calculate total cost
        long long totalCost = 0;
        for (int i = 0; i < n; i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (dist[u][v] == INF) return -1; // impossible
            totalCost += dist[u][v];
        }
        
        return totalCost;
    }
};