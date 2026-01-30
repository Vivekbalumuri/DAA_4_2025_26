class Solution {
public:
    
    bool dfs(int node, vector<vector<int>> &adj,
             vector<bool> &vis, int count, int n) {
        
        // If all vertices are visited
        if (count == n)
            return true;
        
        for (int next : adj[node]) {
            if (!vis[next]) {
                vis[next] = true;
                if (dfs(next, adj, vis, count + 1, n))
                    return true;
                vis[next] = false; // backtrack
            }
        }
        return false;
    }
    
    bool check(int n, int m, vector<vector<int>> &edges) {
        
        // Build adjacency list (0-based indexing)
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Try starting DFS from every vertex
        for (int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            vis[i] = true;
            if (dfs(i, adj, vis, 1, n))
                return true;
        }
        
        return false;
    }
};
