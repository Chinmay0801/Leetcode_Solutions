class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        
        // visited stores best health seen at each cell
        vector<vector<int>> visited(m, vector<int>(n, -1));
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        // BFS: {row, col, current_health}
        queue<tuple<int,int,int>> q;
        
        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;
        
        q.push({0, 0, startHealth});
        visited[0][0] = startHealth;
        
        while (!q.empty()) {
            auto [r, c, h] = q.front(); q.pop();
            
            if (r == m-1 && c == n-1) return true;
            
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d];
                int nc = c + dy[d];
                
                if (nr<0 || nr>=m || nc<0 || nc>=n) continue;
                
                int nh = h - grid[nr][nc];
                
                if (nh <= 0) continue;           // dead
                if (nh <= visited[nr][nc]) continue; // worse or equal path
                
                visited[nr][nc] = nh;
                q.push({nr, nc, nh});
            }
        }
        return false;
    }
};