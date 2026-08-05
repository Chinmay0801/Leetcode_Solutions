class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;

        // Store all rotten oranges and count fresh ones
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(grid[i][j] == 2)
                    q.push({i,j});

                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        if(fresh == 0)
            return 0;

        int minutes = 0;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()) {

            int size = q.size();
            bool rottenThisMinute = false;

            while(size--) {

                auto [r,c] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < rows &&
                       nc >= 0 && nc < cols &&
                       grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        fresh--;
                        rottenThisMinute = true;
                    }
                }
            }

            if(rottenThisMinute)
                minutes++;
        }

        return (fresh == 0) ? minutes : -1;
    }
};