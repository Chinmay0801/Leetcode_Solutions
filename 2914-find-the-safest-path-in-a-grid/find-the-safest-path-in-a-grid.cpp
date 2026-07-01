class Solution {
public:
    int n;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool canReach(vector<vector<int>>& dist, int safe) {
        if (dist[0][0] < safe || dist[n-1][n-1] < safe) return false;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if (r == n-1 && c == n-1) return true;
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d];
                int nc = c + dy[d];
                if (nr>=0 && nr<n && nc>=0 && nc<n 
                    && !visited[nr][nc] 
                    && dist[nr][nc] >= safe) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        // Step 1: Multi-source BFS from all thieves
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d];
                int nc = c + dy[d];
                if (nr>=0 && nr<n && nc>=0 && nc<n && dist[nr][nc]==-1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Step 2: Binary search on safeness value
        int lo = 0, hi = 2 * n, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (canReach(dist, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};