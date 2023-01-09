https://leetcode.com/problems/number-of-enclaves/description/

void bfs(int x, int y, int n, int m, vector<vector<int>>&vis, vector<vector<int>>&grid){
        queue<pair<int,int>>q;
        
        q.push({x, y});
        vis[x][y] = 1;

        int delr[] = {0, 0, 1, -1};
        int delc[] = {1, -1, 0, 0};

        while(!q.empty()){
            auto it = q.front();
            int row = it.first;
            int col = it.second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int newr = delr[i]+row;
                int newc = delc[i]+col;

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && 
                    vis[newr][newc] == 0){
                    q.push({newr, newc});
                    vis[newr][newc] = 1;
                }
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1)
                bfs(i, 0, n, m, vis, grid);
                

            if(grid[i][m-1] == 1)
                bfs(i, m-1, n, m, vis, grid);
                
        }
        for(int j = 0; j < m; j++){
            if(grid[0][j] == 1)
                bfs(0, j, n, m, vis, grid);
                
            if(grid[n-1][j] == 1)
                bfs(n-1, j, n, m, vis, grid);
        }

        int count = 0;
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1)
                    continue;

                if(grid[i][j] == 1 && vis[i][j] == 0)
                    count++;
            }
        }

        return count;
    }
