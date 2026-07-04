class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Build adjacency list {neighbor, distance}
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto& r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        // BFS to find all nodes in component of node 1
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;

        int ans = INT_MAX;

        while (!q.empty()) {
            int node = q.front(); q.pop();

            for (auto& [neighbor, dist] : adj[node]) {
                // update minimum edge in this component
                ans = min(ans, dist);

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return ans;
    }
};